
struct __main_block_impl_0 {
  struct __block_impl impl;
  struct __main_block_desc_0* Desc;
  int *i;
  __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, int *_i, int flags=0) : i(_i) {
    impl.isa = &_NSConcreteStackBlock;
    impl.Flags = flags;
    impl.FuncPtr = fp;
    Desc = desc;
  }
};
static void __main_block_func_0(struct __main_block_impl_0 *__cself) {
  int *i = __cself->i; // bound by copy

            NSLog((NSString *)&__NSConstantStringImpl__var_folders_hg_3gfy4r7s64x2cw3gzfhgllbr0000gn_T_main_e98102_mi_0, (*i));
        }

static struct __main_block_desc_0 {
  size_t reserved;
  size_t Block_size;
} __main_block_desc_0_DATA = { 0, sizeof(struct __main_block_impl_0)};

int main(int argc, const char * argv[]) {
    /* @autoreleasepool */ { __AtAutoreleasePool __autoreleasepool; 
        static int i = 0;
        void (*block)(void) = ((void (*)())&__main_block_impl_0((void *)__main_block_func_0, &__main_block_desc_0_DATA, &i));
        ((void (*)(__block_impl *))((__block_impl *)block)->FuncPtr)((__block_impl *)block);
    }
    return 0;
}
static struct IMAGE_INFO { unsigned version; unsigned flag; } _OBJC_IMAGE_INFO = { 0, 2 };

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        static int i = 0;
        void (^block)(void) = ^{
            NSLog(@"%d", i);
        };
        block();
    }
    return 0;
}
