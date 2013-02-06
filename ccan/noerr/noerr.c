/* CC0 (Public domain) - see LICENSE file for details */
#include "noerr.h"
#include <unistd.h>
#include <errno.h>

int close_noerr(int fd)
{
	int saved_errno = errno, ret;

	while ((ret = close(fd)) != 0) {
		if (errno == EINTR)
			continue;
		ret = errno;
		break;
	}

	errno = saved_errno;
	return ret;
}

int fclose_noerr(FILE *fp)
{
	int saved_errno = errno, ret;

	if (fclose(fp) != 0)
		ret = errno;
	else
		ret = 0;

	errno = saved_errno;
	return ret;
}

int unlink_noerr(const char *pathname)
{
	int saved_errno = errno, ret;

	if (unlink(pathname) != 0)
		ret = errno;
	else
		ret = 0;

	errno = saved_errno;
	return ret;
}
