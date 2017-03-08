/*	$NetBSD: kern_malloc.c,v 1.145 2015/02/06 18:21:29 maxv Exp $	*/

/*
 * Copyright (c) 1987, 1991, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)kern_malloc.c	8.4 (Berkeley) 5/20/95
 */

/*
 * Copyright (c) 1996 Christopher G. Demetriou.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)kern_malloc.c	8.4 (Berkeley) 5/20/95
 */

/*
 * Wrapper interface for obsolete malloc(9).
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: kern_malloc.c,v 1.145 2015/02/06 18:21:29 maxv Exp $");

#include <sys/param.h>
#include <sys/malloc.h>
#include <sys/kmem.h>

#include <rump/rumpuser.h>

/*
 * Built-in malloc types.  Note: ought to be removed.
 */
MALLOC_DEFINE(M_DEVBUF, "devbuf", "device driver memory");
MALLOC_DEFINE(M_DMAMAP, "DMA map", "bus_dma(9) structures");
MALLOC_DEFINE(M_FREE, "free", "should be on free list");
MALLOC_DEFINE(M_TEMP, "temp", "misc. temporary data buffers");
MALLOC_DEFINE(M_RTABLE, "routetbl", "routing tables");
MALLOC_DEFINE(M_FTABLE, "fragtbl", "fragment reassembly header");
MALLOC_DEFINE(M_UFSMNT, "UFS mount", "UFS mount structure");
MALLOC_DEFINE(M_NETADDR, "Export Host", "Export host address structure");
MALLOC_DEFINE(M_MRTABLE, "mrt", "multicast routing tables");

/*
 * Header contains total size, including the header itself.
 */
struct malloc_header {
	size_t		mh_size;
} __aligned(ALIGNBYTES + 1);

void *
rumpns_kern_malloc(unsigned long size, int flags);

void
rumpns_kern_free(void *addr);
void *
rumpns_kern_realloc(void *curaddr, unsigned long newsize, int flags);


void *
rumpns_kern_malloc(unsigned long size, int flags)
{
    void *r = rumpuser_libc_malloc(size);

    if (r == NULL) {
        return NULL;
    }

	if ((flags | M_ZERO) != 0) {
        memset(r, 0, size);
    } else {
        memset(r, 0x41, size);
    }

    return r;
}

void
rumpns_kern_free(void *addr)
{
    rumpuser_libc_free(addr);
}

void *
rumpns_kern_realloc(void *curaddr, unsigned long newsize, int flags)
{
	return rumpuser_libc_realloc(curaddr, newsize);
}
