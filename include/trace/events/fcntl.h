/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM fcntl

#if !defined(_TRACE_EVENTS_FCNTL_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_EVENTS_FCNTL_H

#include <linux/tracepoint.h>
#include <linux/file.h>
#include <linux/device.h>
#include <linux/kdev_t.h>

TRACE_EVENT(fcntl,
	TP_PROTO(const struct inode *inode, unsigned int cmd, unsigned long arg,
		     long *err),

	TP_ARGS(inode, cmd, arg, err),

	TP_STRUCT__entry(
	    __field(dev_t, dev)
	    __field(unsigned long, i_ino)
	    __field(unsigned int, cmd)
	    __field(unsigned long, arg)
	    __field(long, ret)
	),

	TP_fast_assign(
	    __entry->dev	= inode->i_sb->s_dev;
	    __entry->i_ino	= inode->i_ino;
	    __entry->cmd	= cmd;
	    __entry->arg	= arg;
	    __entry->ret	= *err;
	),

	TP_printk("dev=%d,%d ino=%lu cmd=%u arg=0x%lx, ret=%ld",
	    MAJOR(__entry->dev), MINOR(__entry->dev), __entry->i_ino,
	    __entry->cmd, __entry->arg, __entry->ret)
);

#endif /* _TRACE_EVENTS_FCNTL_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
