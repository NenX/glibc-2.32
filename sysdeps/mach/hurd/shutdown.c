/* Copyright (C) 1992-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#include <errno.h>
#include <sys/socket.h>
#include <hurd.h>
#include <hurd/socket.h>
#include <hurd/fd.h>

/* Shut down all or part of the connection open on socket FD.
   HOW determines what to shut down:
     0 = No more receptions;
     1 = No more transmissions;
     2 = No more receptions or transmissions.
   Returns 0 on success, -1 for errors.  */
/* XXX should be __shutdown ? */
int
shutdown (int fd, int how)
{
  error_t err = HURD_DPORT_USE (fd, __socket_shutdown (port, how));
  if (err)
    return __hurd_dfail (fd, err);
  return 0;
}
