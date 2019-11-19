//
//  main.m
//  Debug-block
//
//  Created by BowenCoder on 2019/11/10.
//

#import <Foundation/Foundation.h>

/*
 MRC：-fno-objc-arc
 Block的实现、变量的捕获以及__block的作用
 */

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        __block NSObject *obj = [[NSObject alloc] init];
        void (^block)(void) = ^{
            NSLog(@"%@", obj);
        };
        block();
    }
    return 0;
}
