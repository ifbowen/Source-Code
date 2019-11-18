//
//  main.m
//  Debug-malloc
//
//  Created by BowenCoder on 2019/11/10.
//

#import <Foundation/Foundation.h>
#import <malloc/malloc.h>

/*
 参考：https://www.jianshu.com/p/cb1b573a0297
 项目-Targets-Build Settings Compile Sources AS：
 1、OC和C++混编造成其它类错误的问题(Compile Sources As Objective-C++)
 2、修改文件后缀.mm
 */

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        char *ptr = (char *)(malloc(24)); // 动态分配24个字节
        NSLog(@"所占大小%lu",malloc_size(ptr));//打印32，分配16的整数倍
    }
    return 0;
}
