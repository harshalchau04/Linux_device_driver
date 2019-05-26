#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xbca7617b, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x65fa13d2, __VMLINUX_SYMBOL_STR(param_get_int) },
	{ 0x3291cd25, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x748269e3, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x4f62be74, __VMLINUX_SYMBOL_STR(param_array_ops) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x15c875ba, __VMLINUX_SYMBOL_STR(param_set_int) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "ACF4BEEAF9AF421F5C01CFE");
