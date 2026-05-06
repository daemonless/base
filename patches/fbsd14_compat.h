/*
 * FreeBSD 14 compatibility header for s6 source builds.
 *
 * FreeBSD 15 introduced libsys.so.7 which renumbered setgroups() from
 * syscall 80 (FBSD_1.0) to syscall 596 (FBSD_1.8). Binaries compiled on
 * FreeBSD 15 reference setgroups@@FBSD_1.8 which does not exist on FreeBSD 14.
 *
 */
#if defined(__FreeBSD__) && __FreeBSD__ >= 15
__asm__(".symver setgroups, setgroups@FBSD_1.0");
#endif
