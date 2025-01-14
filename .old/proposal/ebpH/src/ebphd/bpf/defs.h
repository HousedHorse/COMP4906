/* ebpH --  An eBPF intrusion detection program.
 * -------  Monitors system call patterns and detect anomalies.
 * Copyright 2019 William Findlay (williamfindlay@cmail.carleton.ca) and
 * Anil Somayaji (soma@scs.carleton.ca)
 *
 * Based on Anil Somayaji's pH
 *  http://people.scs.carleton.ca/~mvvelzen/pH/pH.html
 *  Copyright 2003 Anil Somayaji
 *
 * USAGE: ebphd <COMMAND>
 *
 * Licensed under GPL v2 License */

#ifndef DEFS_H
#define DEFS_H

#include <uapi/asm/unistd_64.h>

/* This is the default size for BPF tables (hashmaps, etc.) */
#define EBPH_DEFAULT_TABLE_SIZE 10240
/* This is the maxmimum number of PIDs on the system */
#define EBPH_PROCESSES_TABLE_SIZE 4194304
#define EBPH_PROFILES_TABLE_SIZE  EBPH_DEFAULT_TABLE_SIZE

/* Profile stuff below this line -------------------------- */
/* Length of a syscall sequence */
#define EBPH_SEQLEN  9

/* Window size for locality frames */
#define EBPH_LOCALITY_WIN  128

/* Total number of systemcalls in the current kernel version
 * Keep this updated with the latest version of Linux */
#define EBPH_NUM_SYSCALLS 450
/* Size of each array of lookahead pairs */
#define EBPH_LOOKAHEAD_ARRAY_SIZE EBPH_NUM_SYSCALLS * EBPH_NUM_SYSCALLS

/* Amount of time a profile must remain frozen before becoming normal */
#define EBPH_NORMAL_WAIT (u64) 24 * 7 * 3600 * 1000000000 /* One week in nanoseconds */
/* 3 seconds in nanoseconds uncomment this and comment the above for quick testing */
//#define EBPH_NORMAL_WAIT (u64) 3 * 1000000000

/* Multiply by a profile's train_count and compare with... */
#define EBPH_NORMAL_FACTOR_DEN 32
/* ... this, multiplied by a profile's normal_count */
#define EBPH_NORMAL_FACTOR 128

/* Number of anomalies allowed before a profile is no longer considered normal */
#define EBPH_ANOMALY_LIMIT 30

/* Maximum length for a filename... This seems fine for now. */
#define EBPH_FILENAME_LEN 128

/* Systemcall stuff below this line -------------------------- */
#define EBPH_CLONE      56
#define EBPH_FORK       57
#define EBPH_VFORK      58
#define EBPH_EXECVE     59
#define EBPH_EXECVEAT   __NR_execveat
#define EBPH_EXIT       60
#define EBPH_WAIT       61
#define EBPH_EXIT_GROUP 231
#define EBPH_EMPTY      9999

#endif
/* DEFS_H */
