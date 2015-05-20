/* $NetBSD: svr4_sysent.c,v 1.89 2015/03/07 16:41:54 christos Exp $ */

/*
 * System call switch table.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * created from	NetBSD: syscalls.master,v 1.62 2013/11/07 19:37:19 njoly Exp
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: svr4_sysent.c,v 1.89 2015/03/07 16:41:54 christos Exp $");

#if defined(_KERNEL_OPT)
#include "opt_ntp.h"
#include "opt_sysv.h"
#endif
#include <sys/param.h>
#include <sys/systm.h>
#include <sys/signal.h>
#include <sys/mount.h>
#include <sys/poll.h>
#include <sys/sched.h>
#include <sys/syscallargs.h>
#include <compat/svr4/svr4_types.h>
#include <compat/svr4/svr4_time.h>
#include <compat/svr4/svr4_signal.h>
#include <compat/svr4/svr4_ucontext.h>
#include <compat/svr4/svr4_lwp.h>
#include <compat/svr4/svr4_syscallargs.h>
#include <compat/svr4/svr4_statvfs.h>
#include <compat/svr4/svr4_resource.h>
#include <compat/svr4/svr4_acl.h>
#include <compat/svr4/svr4_schedctl.h>

#define	s(type)	sizeof(type)
#define	n(type)	(sizeof(type)/sizeof (register_t))
#define	ns(type)	n(type), s(type)

struct sysent svr4_sysent[] = {
	{ 0, 0, 0,
	    (sy_call_t *)sys_nosys, 0, 0 },		/* 0 = syscall */
	{ ns(struct sys_exit_args), 0,
	    (sy_call_t *)sys_exit, 0, 0 },		/* 1 = exit */
	{ 0, 0, 0,
	    (sy_call_t *)sys_fork, 0, 0 },		/* 2 = fork */
	{ ns(struct sys_read_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_read, 0, 0 },		/* 3 = read */
	{ ns(struct sys_write_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_write, 0, 0 },		/* 4 = write */
	{ ns(struct svr4_sys_open_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_open, 0, 0 },	/* 5 = open */
	{ ns(struct sys_close_args), 0,
	    (sy_call_t *)sys_close, 0, 0 },		/* 6 = close */
	{ ns(struct svr4_sys_wait_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_wait, 0, 0 },	/* 7 = wait */
	{ ns(struct svr4_sys_creat_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_creat, 0, 0 },	/* 8 = creat */
	{ ns(struct sys_link_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_link, 0, 0 },		/* 9 = link */
	{ ns(struct sys_unlink_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_unlink, 0, 0 },		/* 10 = unlink */
	{ ns(struct svr4_sys_execv_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_execv, 0, 0 },	/* 11 = execv */
	{ ns(struct sys_chdir_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_chdir, 0, 0 },		/* 12 = chdir */
	{ ns(struct svr4_sys_time_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_time, 0, 0 },	/* 13 = time */
	{ ns(struct svr4_sys_mknod_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_mknod, 0, 0 },	/* 14 = mknod */
	{ ns(struct sys_chmod_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_chmod, 0, 0 },		/* 15 = chmod */
	{ ns(struct sys___posix_chown_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys___posix_chown, 0, 0 },	/* 16 = chown */
	{ ns(struct svr4_sys_break_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_break, 0, 0 },	/* 17 = break */
	{ ns(struct svr4_sys_stat_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_stat, 0, 0 },	/* 18 = stat */
	{ ns(struct compat_43_sys_lseek_args), 0,
	    (sy_call_t *)compat_43_sys_lseek, 0, 0 },	/* 19 = lseek */
	{ 0, 0, 0,
	    (sy_call_t *)sys_getpid, 0, 0 },		/* 20 = getpid */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 21 = unimplemented old_mount */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 22 = unimplemented System V umount */
	{ ns(struct sys_setuid_args), 0,
	    (sy_call_t *)sys_setuid, 0, 0 },		/* 23 = setuid */
	{ 0, 0, 0,
	    (sy_call_t *)sys_getuid_with_euid, 0, 0 },/* 24 = getuid_with_euid */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 25 = unimplemented stime */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 26 = unimplemented ptrace */
	{ ns(struct svr4_sys_alarm_args), 0,
	    (sy_call_t *)svr4_sys_alarm, 0, 0 },	/* 27 = alarm */
	{ ns(struct svr4_sys_fstat_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_fstat, 0, 0 },	/* 28 = fstat */
	{ 0, 0, 0,
	    (sy_call_t *)svr4_sys_pause, 0, 0 },	/* 29 = pause */
	{ ns(struct svr4_sys_utime_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_utime, 0, 0 },	/* 30 = utime */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 31 = unimplemented was stty */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 32 = unimplemented was gtty */
	{ ns(struct svr4_sys_access_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_access, 0, 0 },	/* 33 = access */
	{ ns(struct svr4_sys_nice_args), 0,
	    (sy_call_t *)svr4_sys_nice, 0, 0 },	/* 34 = nice */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 35 = unimplemented statfs */
	{ 0, 0, 0,
	    (sy_call_t *)sys_sync, 0, 0 },		/* 36 = sync */
	{ ns(struct svr4_sys_kill_args), 0,
	    (sy_call_t *)svr4_sys_kill, 0, 0 },	/* 37 = kill */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 38 = unimplemented fstatfs */
	{ ns(struct svr4_sys_pgrpsys_args), 0,
	    (sy_call_t *)svr4_sys_pgrpsys, 0, 0 },	/* 39 = pgrpsys */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 40 = unimplemented xenix */
	{ ns(struct sys_dup_args), 0,
	    (sy_call_t *)sys_dup, 0, 0 },		/* 41 = dup */
	{ 0, 0, 0,
	    (sy_call_t *)sys_pipe, 0, 0 },		/* 42 = pipe */
	{ ns(struct svr4_sys_times_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_times, 0, 0 },	/* 43 = times */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 44 = unimplemented profil */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 45 = unimplemented plock */
	{ ns(struct sys_setgid_args), 0,
	    (sy_call_t *)sys_setgid, 0, 0 },		/* 46 = setgid */
	{ 0, 0, 0,
	    (sy_call_t *)sys_getgid_with_egid, 0, 0 },/* 47 = getgid_with_egid */
	{ ns(struct svr4_sys_signal_args), 0,
	    (sy_call_t *)svr4_sys_signal, 0, 0 },	/* 48 = signal */
#ifdef SYSVMSG
	{ ns(struct svr4_sys_msgsys_args), 0,
	    (sy_call_t *)svr4_sys_msgsys, 0, 0 },	/* 49 = msgsys */
#else
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 49 = unimplemented msgsys */
#endif
	{ ns(struct svr4_sys_sysarch_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_sysarch, 0, 0 },	/* 50 = sysarch */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 51 = unimplemented acct */
#ifdef SYSVSHM
	{ ns(struct svr4_sys_shmsys_args), 0,
	    (sy_call_t *)svr4_sys_shmsys, 0, 0 },	/* 52 = shmsys */
#else
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 52 = unimplemented shmsys */
#endif
#ifdef SYSVSEM
	{ ns(struct svr4_sys_semsys_args), 0,
	    (sy_call_t *)svr4_sys_semsys, 0, 0 },	/* 53 = semsys */
#else
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 53 = unimplemented semsys */
#endif
	{ ns(struct svr4_sys_ioctl_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_ioctl, 0, 0 },	/* 54 = ioctl */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 55 = unimplemented uadmin */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 56 = unimplemented exch */
	{ ns(struct svr4_sys_utssys_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_utssys, 0, 0 },	/* 57 = utssys */
	{ ns(struct sys_fsync_args), 0,
	    (sy_call_t *)sys_fsync, 0, 0 },		/* 58 = fsync */
	{ ns(struct svr4_sys_execve_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_execve, 0, 0 },	/* 59 = execve */
	{ ns(struct sys_umask_args), 0,
	    (sy_call_t *)sys_umask, 0, 0 },		/* 60 = umask */
	{ ns(struct sys_chroot_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_chroot, 0, 0 },		/* 61 = chroot */
	{ ns(struct svr4_sys_fcntl_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_fcntl, 0, 0 },	/* 62 = fcntl */
	{ ns(struct svr4_sys_ulimit_args), 0,
	    (sy_call_t *)svr4_sys_ulimit, 0, 0 },	/* 63 = ulimit */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 64 = unimplemented reserved for unix/pc */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 65 = unimplemented reserved for unix/pc */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 66 = unimplemented reserved for unix/pc */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 67 = unimplemented reserved for unix/pc */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 68 = unimplemented reserved for unix/pc */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 69 = unimplemented reserved for unix/pc */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 70 = obsolete advfs */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 71 = obsolete unadvfs */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 72 = obsolete rmount */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 73 = obsolete rumount */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 74 = obsolete rfstart */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 75 = obsolete sigret */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 76 = obsolete rdebug */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 77 = obsolete rfstop */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 78 = unimplemented rfsys */
	{ ns(struct sys_rmdir_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_rmdir, 0, 0 },		/* 79 = rmdir */
	{ ns(struct sys_mkdir_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_mkdir, 0, 0 },		/* 80 = mkdir */
	{ ns(struct svr4_sys_getdents_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_getdents, 0, 0 },	/* 81 = getdents */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 82 = obsolete libattach */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 83 = obsolete libdetach */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 84 = unimplemented sysfs */
	{ ns(struct svr4_sys_getmsg_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_getmsg, 0, 0 },	/* 85 = getmsg */
	{ ns(struct svr4_sys_putmsg_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_putmsg, 0, 0 },	/* 86 = putmsg */
	{ ns(struct sys_poll_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_poll, 0, 0 },		/* 87 = poll */
	{ ns(struct svr4_sys_lstat_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_lstat, 0, 0 },	/* 88 = lstat */
	{ ns(struct sys_symlink_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_symlink, 0, 0 },		/* 89 = symlink */
	{ ns(struct sys_readlink_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_readlink, 0, 0 },	/* 90 = readlink */
	{ ns(struct sys_getgroups_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_getgroups, 0, 0 },	/* 91 = getgroups */
	{ ns(struct sys_setgroups_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_setgroups, 0, 0 },	/* 92 = setgroups */
	{ ns(struct sys_fchmod_args), 0,
	    (sy_call_t *)sys_fchmod, 0, 0 },		/* 93 = fchmod */
	{ ns(struct sys___posix_fchown_args), 0,
	    (sy_call_t *)sys___posix_fchown, 0, 0 },	/* 94 = fchown */
	{ ns(struct svr4_sys_sigprocmask_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_sigprocmask, 0, 0 },/* 95 = sigprocmask */
	{ ns(struct svr4_sys_sigsuspend_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_sigsuspend, 0, 0 },	/* 96 = sigsuspend */
	{ ns(struct svr4_sys_sigaltstack_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_sigaltstack, 0, 0 },/* 97 = sigaltstack */
	{ ns(struct svr4_sys_sigaction_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_sigaction, 0, 0 },	/* 98 = sigaction */
	{ ns(struct svr4_sys_sigpending_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_sigpending, 0, 0 },	/* 99 = sigpending */
	{ ns(struct svr4_sys_context_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_context, 0, 0 },	/* 100 = context */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 101 = unimplemented evsys */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 102 = unimplemented evtrapret */
	{ ns(struct svr4_sys_statvfs_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_statvfs, 0, 0 },	/* 103 = statvfs */
	{ ns(struct svr4_sys_fstatvfs_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_fstatvfs, 0, 0 },	/* 104 = fstatvfs */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 105 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 106 = unimplemented nfssvc */
	{ ns(struct svr4_sys_waitsys_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_waitsys, 0, 0 },	/* 107 = waitsys */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 108 = unimplemented sigsendsys */
	{ ns(struct svr4_sys_hrtsys_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_hrtsys, 0, 0 },	/* 109 = hrtsys */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 110 = unimplemented acancel */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 111 = unimplemented async */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 112 = unimplemented priocntlsys */
	{ ns(struct svr4_sys_pathconf_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_pathconf, 0, 0 },	/* 113 = pathconf */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 114 = unimplemented mincore */
	{ ns(struct svr4_sys_mmap_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_mmap, 0, 0 },	/* 115 = mmap */
	{ ns(struct sys_mprotect_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_mprotect, 0, 0 },	/* 116 = mprotect */
	{ ns(struct sys_munmap_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_munmap, 0, 0 },		/* 117 = munmap */
	{ ns(struct svr4_sys_fpathconf_args), 0,
	    (sy_call_t *)svr4_sys_fpathconf, 0, 0 },	/* 118 = fpathconf */
	{ 0, 0, 0,
	    (sy_call_t *)sys_vfork, 0, 0 },		/* 119 = vfork */
	{ ns(struct sys_fchdir_args), 0,
	    (sy_call_t *)sys_fchdir, 0, 0 },		/* 120 = fchdir */
	{ ns(struct sys_readv_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_readv, 0, 0 },		/* 121 = readv */
	{ ns(struct sys_writev_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_writev, 0, 0 },		/* 122 = writev */
	{ ns(struct svr4_sys_xstat_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_xstat, 0, 0 },	/* 123 = xstat */
	{ ns(struct svr4_sys_lxstat_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_lxstat, 0, 0 },	/* 124 = lxstat */
	{ ns(struct svr4_sys_fxstat_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_fxstat, 0, 0 },	/* 125 = fxstat */
	{ ns(struct svr4_sys_xmknod_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_xmknod, 0, 0 },	/* 126 = xmknod */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 127 = unimplemented clocal */
	{ ns(struct svr4_sys_setrlimit_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_setrlimit, 0, 0 },	/* 128 = setrlimit */
	{ ns(struct svr4_sys_getrlimit_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_getrlimit, 0, 0 },	/* 129 = getrlimit */
	{ ns(struct sys___posix_lchown_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys___posix_lchown, 0, 0 },	/* 130 = lchown */
	{ ns(struct svr4_sys_memcntl_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_memcntl, 0, 0 },	/* 131 = memcntl */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 132 = unimplemented getpmsg */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 133 = unimplemented putpmsg */
	{ ns(struct sys___posix_rename_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys___posix_rename, 0, 0 },	/* 134 = rename */
	{ ns(struct svr4_sys_uname_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_uname, 0, 0 },	/* 135 = uname */
	{ ns(struct sys_setegid_args), 0,
	    (sy_call_t *)sys_setegid, 0, 0 },		/* 136 = setegid */
	{ ns(struct svr4_sys_sysconfig_args), 0,
	    (sy_call_t *)svr4_sys_sysconfig, 0, 0 },	/* 137 = sysconfig */
	{ ns(struct compat_50_sys_adjtime_args), SYCALL_ARG_PTR,
	    (sy_call_t *)compat_50_sys_adjtime, 0, 0 },/* 138 = adjtime */
	{ ns(struct svr4_sys_systeminfo_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_systeminfo, 0, 0 },	/* 139 = systeminfo */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 140 = unimplemented */
	{ ns(struct sys_seteuid_args), 0,
	    (sy_call_t *)sys_seteuid, 0, 0 },		/* 141 = seteuid */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 142 = unimplemented vtrace */
	{ 0, 0, 0,
	    (sy_call_t *)sys_fork, 0, 0 },		/* 143 = fork1 */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 144 = unimplemented sigtimedwait */
	{ ns(struct svr4_sys__lwp_info_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys__lwp_info, 0, 0 },	/* 145 = _lwp_info */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 146 = unimplemented yield */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 147 = unimplemented lwp_sema_wait */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 148 = unimplemented lwp_sema_post */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 149 = unimplemented lwp_sema_trywait */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 150 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 151 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 152 = unimplemented modctl */
	{ ns(struct sys_fchroot_args), 0,
	    (sy_call_t *)sys_fchroot, 0, 0 },		/* 153 = fchroot */
	{ ns(struct svr4_sys_utimes_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_utimes, 0, 0 },	/* 154 = utimes */
	{ 0, 0, 0,
	    (sy_call_t *)svr4_sys_vhangup, 0, 0 },	/* 155 = vhangup */
	{ ns(struct svr4_sys_gettimeofday_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_gettimeofday, 0, 0 },/* 156 = gettimeofday */
	{ ns(struct compat_50_sys_getitimer_args), SYCALL_ARG_PTR,
	    (sy_call_t *)compat_50_sys_getitimer, 0, 0 },/* 157 = getitimer */
	{ ns(struct compat_50_sys_setitimer_args), SYCALL_ARG_PTR,
	    (sy_call_t *)compat_50_sys_setitimer, 0, 0 },/* 158 = setitimer */
	{ ns(struct svr4_sys__lwp_create_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys__lwp_create, 0, 0 },/* 159 = _lwp_create */
	{ 0, 0, 0,
	    (sy_call_t *)svr4_sys__lwp_exit, 0, 0 },	/* 160 = _lwp_exit */
	{ ns(struct svr4_sys__lwp_suspend_args), 0,
	    (sy_call_t *)svr4_sys__lwp_suspend, 0, 0 },/* 161 = _lwp_suspend */
	{ ns(struct svr4_sys__lwp_continue_args), 0,
	    (sy_call_t *)svr4_sys__lwp_continue, 0, 0 },/* 162 = _lwp_continue */
	{ ns(struct svr4_sys__lwp_kill_args), 0,
	    (sy_call_t *)svr4_sys__lwp_kill, 0, 0 },	/* 163 = _lwp_kill */
	{ 0, 0, 0,
	    (sy_call_t *)svr4_sys__lwp_self, 0, 0 },	/* 164 = _lwp_self */
	{ 0, 0, 0,
	    (sy_call_t *)svr4_sys__lwp_getprivate, 0, 0 },/* 165 = _lwp_getprivate */
	{ ns(struct svr4_sys__lwp_setprivate_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys__lwp_setprivate, 0, 0 },/* 166 = _lwp_setprivate */
	{ ns(struct svr4_sys__lwp_wait_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys__lwp_wait, 0, 0 },	/* 167 = _lwp_wait */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 168 = unimplemented lwp_mutex_unlock */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 169 = unimplemented lwp_mutex_lock */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 170 = unimplemented lwp_cond_wait */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 171 = unimplemented lwp_cond_signal */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 172 = unimplemented lwp_cond_broadcast */
	{ ns(struct svr4_sys_pread_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_pread, 0, 0 },	/* 173 = pread */
	{ ns(struct svr4_sys_pwrite_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_pwrite, 0, 0 },	/* 174 = pwrite */
	{ ns(struct svr4_sys_llseek_args), 0,
	    (sy_call_t *)svr4_sys_llseek, 0, 0 },	/* 175 = llseek */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 176 = unimplemented inst_sync */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 177 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 178 = unimplemented kaio */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 179 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 180 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 181 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 182 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 183 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 184 = unimplemented tsolsys */
	{ ns(struct svr4_sys_acl_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_acl, 0, 0 },	/* 185 = acl */
	{ ns(struct svr4_sys_auditsys_args), 0,
	    (sy_call_t *)svr4_sys_auditsys, 0, 0 },	/* 186 = auditsys */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 187 = unimplemented processor_bind */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 188 = unimplemented processor_info */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 189 = unimplemented p_online */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 190 = unimplemented sigqueue */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 191 = unimplemented clock_gettime */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 192 = unimplemented clock_settime */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 193 = unimplemented clock_getres */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 194 = unimplemented timer_create */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 195 = unimplemented timer_delete */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 196 = unimplemented timer_settime */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 197 = unimplemented timer_gettime */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 198 = unimplemented timer_getoverrun */
	{ ns(struct compat_50_sys_nanosleep_args), SYCALL_ARG_PTR,
	    (sy_call_t *)compat_50_sys_nanosleep, 0, 0 },/* 199 = nanosleep */
	{ ns(struct svr4_sys_facl_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_facl, 0, 0 },	/* 200 = facl */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 201 = unimplemented door */
	{ ns(struct sys_setreuid_args), 0,
	    (sy_call_t *)sys_setreuid, 0, 0 },	/* 202 = setreuid */
	{ ns(struct sys_setregid_args), 0,
	    (sy_call_t *)sys_setregid, 0, 0 },	/* 203 = setregid */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 204 = unimplemented install_utrap */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 205 = unimplemented signotify */
	{ ns(struct svr4_sys_schedctl_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_schedctl, 0, 0 },	/* 206 = schedctl */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 207 = unimplemented pset */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 208 = unimplemented */
	{ ns(struct svr4_sys_resolvepath_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_resolvepath, 0, 0 },/* 209 = resolvepath */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 210 = unimplemented signotifywait */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 211 = unimplemented lwp_sigredirect */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 212 = unimplemented lwp_alarm */
	{ ns(struct svr4_sys_getdents64_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_getdents64, 0, 0 },	/* 213 = getdents64 */
	{ ns(struct svr4_sys_mmap64_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_mmap64, 0, 0 },	/* 214 = mmap64 */
	{ ns(struct svr4_sys_stat64_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_stat64, 0, 0 },	/* 215 = stat64 */
	{ ns(struct svr4_sys_lstat64_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_lstat64, 0, 0 },	/* 216 = lstat64 */
	{ ns(struct svr4_sys_fstat64_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_fstat64, 0, 0 },	/* 217 = fstat64 */
	{ ns(struct svr4_sys_statvfs64_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_statvfs64, 0, 0 },	/* 218 = statvfs64 */
	{ ns(struct svr4_sys_fstatvfs64_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_fstatvfs64, 0, 0 },	/* 219 = fstatvfs64 */
	{ ns(struct svr4_sys_setrlimit64_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_setrlimit64, 0, 0 },/* 220 = setrlimit64 */
	{ ns(struct svr4_sys_getrlimit64_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_getrlimit64, 0, 0 },/* 221 = getrlimit64 */
	{ ns(struct svr4_sys_pread64_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_pread64, 0, 0 },	/* 222 = pread64 */
	{ ns(struct svr4_sys_pwrite64_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_pwrite64, 0, 0 },	/* 223 = pwrite64 */
	{ ns(struct svr4_sys_creat64_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_creat64, 0, 0 },	/* 224 = creat64 */
	{ ns(struct svr4_sys_open64_args), SYCALL_ARG_PTR,
	    (sy_call_t *)svr4_sys_open64, 0, 0 },	/* 225 = open64 */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 226 = unimplemented rpcsys */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 227 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 228 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 229 = unimplemented */
	{ ns(struct svr4_sys_socket_args), 0,
	    (sy_call_t *)svr4_sys_socket, 0, 0 },	/* 230 = socket */
	{ ns(struct sys_socketpair_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_socketpair, 0, 0 },	/* 231 = socketpair */
	{ ns(struct sys_bind_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_bind, 0, 0 },		/* 232 = bind */
	{ ns(struct sys_listen_args), 0,
	    (sy_call_t *)sys_listen, 0, 0 },		/* 233 = listen */
	{ ns(struct compat_43_sys_accept_args), SYCALL_ARG_PTR,
	    (sy_call_t *)compat_43_sys_accept, 0, 0 },/* 234 = accept */
	{ ns(struct sys_connect_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_connect, 0, 0 },		/* 235 = connect */
	{ ns(struct sys_shutdown_args), 0,
	    (sy_call_t *)sys_shutdown, 0, 0 },	/* 236 = shutdown */
	{ ns(struct compat_43_sys_recv_args), SYCALL_ARG_PTR,
	    (sy_call_t *)compat_43_sys_recv, 0, 0 },	/* 237 = recv */
	{ ns(struct compat_43_sys_recvfrom_args), SYCALL_ARG_PTR,
	    (sy_call_t *)compat_43_sys_recvfrom, 0, 0 },/* 238 = recvfrom */
	{ ns(struct compat_43_sys_recvmsg_args), SYCALL_ARG_PTR,
	    (sy_call_t *)compat_43_sys_recvmsg, 0, 0 },/* 239 = recvmsg */
	{ ns(struct compat_43_sys_send_args), SYCALL_ARG_PTR,
	    (sy_call_t *)compat_43_sys_send, 0, 0 },	/* 240 = send */
	{ ns(struct compat_43_sys_sendmsg_args), SYCALL_ARG_PTR,
	    (sy_call_t *)compat_43_sys_sendmsg, 0, 0 },/* 241 = sendmsg */
	{ ns(struct sys_sendto_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_sendto, 0, 0 },		/* 242 = sendto */
	{ ns(struct compat_43_sys_getpeername_args), SYCALL_ARG_PTR,
	    (sy_call_t *)compat_43_sys_getpeername, 0, 0 },/* 243 = getpeername */
	{ ns(struct compat_43_sys_getsockname_args), SYCALL_ARG_PTR,
	    (sy_call_t *)compat_43_sys_getsockname, 0, 0 },/* 244 = getsockname */
	{ ns(struct sys_getsockopt_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_getsockopt, 0, 0 },	/* 245 = getsockopt */
	{ ns(struct sys_setsockopt_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_setsockopt, 0, 0 },	/* 246 = setsockopt */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 247 = unimplemented sockconfig */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 248 = unimplemented sys_ntp_gettime */
#if defined(NTP) || !defined(_KERNEL)
	{ ns(struct sys_ntp_adjtime_args), SYCALL_ARG_PTR,
	    (sy_call_t *)sys_ntp_adjtime, 0, 0 },	/* 249 = ntp_adjtime */
#else
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 249 = excluded ntp_adjtime */
#endif
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 250 = unimplemented lwp_mutex_unlock */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 251 = unimplemented lwp_mutex_trylock */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 252 = unimplemented lwp_mutex_init */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 253 = unimplemented cladm */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 254 = unimplemented lwp_sigtimedwait */
	{ 0, 0, 0,
	    sys_nosys, 0, 0 },			/* 255 = unimplemented umount2 */
};
