
/**
 iOS源码解析：Block的本质
 https://www.itcodemonkey.com/article/13158.html
 ios block 源码分析
 http://kuiyu.top/2019/01/14/ios-block-%E5%88%86%E6%9E%90/
 */

struct __block_impl {
  void *isa;
  int Flags;
  int Reserved;
  void *FuncPtr;
};

/**
3.将1中创建的_main_block_func_0这个函数的地址，和2中创建的_main_block_desc_0这个结构体的地址传给_main_block_impl_0的构造函数。
4.利用_main_block_func_0初始化_main_block_impl_0结构体的第一个成员变量impl的成员变量FuncPtr。
  这样_main_bck_impl_0这个结构体也就得到了block中那个代码块的地址。
 5.利用_mian_block_desc_0_DATA去初始化_mian_block_impl_0的第二个成员变量Desc
*/
struct __main_block_impl_0 {
    struct __block_impl impl;
    struct __main_block_desc_0* Desc;
    /**
     这是一个C++的结构体。而且在这个结构体内还包含一个函数，这个函数的函数名和结构体名称一致，这在C语言中是没有的，这是C++特有的。     在C++的结构体包含的函数称为结构体的构造函数，它就相当于是OC中的init方法，用来初始化结构体。OC中的init方法返回的是对象本身，
     C++的结构体中的构造方法返回的也是结构体对象。
     */
    __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, int flags=0) {
        impl.isa = &_NSConcreteStackBlock;
        impl.Flags = flags;
        impl.FuncPtr = fp;
        Desc = desc;
    }
};

// 1.创建一个函数_main_block_func_0,这个函数的作用就是将我们block中要执行的代码封装到函数内部，方便调用。
static void __main_block_func_0(struct __main_block_impl_0 *__cself) {
    
    NSLog((NSString *)&__NSConstantStringImpl__var_folders_hg_3gfy4r7s64x2cw3gzfhgllbr0000gn_T_main_ed45b6_mi_0);
}

// 2.创建一个结构体_main_block_desc_0,这个结构体中主要包含_main_block_impl_0这个结构体占用的存储空间大小等信息
static struct __main_block_desc_0 {
    size_t reserved;
    size_t Block_size;
} __main_block_desc_0_DATA = { 0, sizeof(struct __main_block_impl_0)};

int main(int argc, const char * argv[]) {
    /* @autoreleasepool */ { __AtAutoreleasePool __autoreleasepool;
        
        // 取__main_block_impl_0函数返回值的地址，赋值给block这个指针，block指向的就是初始化后的_main_block_impl_0结构体对象
        void (*block)(void) = ((void (*)())&__main_block_impl_0((void *)__main_block_func_0, &__main_block_desc_0_DATA));
        /**
         为什么可以这样强制转换(__block_impl *)呢？
         因为block指向的是_main_block_impl_0这个结构体的首地址，而_main_block_impl_0的第一个成员变量是struct __block_impl impl;
         所以impl和_main_block_impl_0的首地址是一样的，因此指向_main_block_impl_0的首地址的指针也就可以被强制转换为指向impl的首地址的指针。
         
         之前初始化的时候FuncPtr这个指针在构造函数中是被初始化为指向_mian_block_func_0这个函数的地址。
         因此通过block->FuncPtr调用也就获取了_main_block_func_0这个函数的地址，
         然后对_main_block_func_0进行调用，也就是执行block中的代码了。
         这中间block又被当做参数传进了_main_block_func_0这个函数。
         */
        ((void (*)(__block_impl *))((__block_impl *)block)->FuncPtr)((__block_impl *)block);
    }
    return 0;
}

static struct IMAGE_INFO { unsigned version; unsigned flag; } _OBJC_IMAGE_INFO = { 0, 2 };


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        void (^block)(void) = ^{
            NSLog(@"123");
        };
        block();
    }
    return 0;
}
