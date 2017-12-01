	.file	"main.cpp"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	make_static_call
	.type	make_static_call, @function
make_static_call:
.LFB0:
	.cfi_startproc
	subl	$24, %esp
	.cfi_def_cfa_offset 28
	pushl	28(%esp)
	.cfi_def_cfa_offset 32
	call	_ZN5Class22static_dispatch_methodEv
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE0:
	.size	make_static_call, .-make_static_call
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4,,15
	.globl	make_virtual_call
	.type	make_virtual_call, @function
make_virtual_call:
.LFB1:
	.cfi_startproc
	subl	$24, %esp
	.cfi_def_cfa_offset 28
	movl	28(%esp), %eax
	movl	(%eax), %edx
	pushl	%eax
	.cfi_def_cfa_offset 32
	call	*8(%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE1:
	.size	make_virtual_call, .-make_virtual_call
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.section	.text.unlikely
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4,,15
	.globl	make_virtual_call_2
	.type	make_virtual_call_2, @function
make_virtual_call_2:
.LFB2:
	.cfi_startproc
	subl	$24, %esp
	.cfi_def_cfa_offset 28
	movl	28(%esp), %eax
	movl	(%eax), %edx
	pushl	%eax
	.cfi_def_cfa_offset 32
	call	*12(%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE2:
	.size	make_virtual_call_2, .-make_virtual_call_2
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
