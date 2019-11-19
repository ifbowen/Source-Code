//
//  main.m
//  Debug-block
//
//  Created by BowenCoder on 2019/11/10.
//

#import <Foundation/Foundation.h>

/* 
 Block的实现、变量的捕获以及__block的作用
 */

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSObject *obj = [[NSObject alloc] init];
        __block __weak NSObject *weakObj = obj;
        void (^block)(void) = ^{
            NSLog(@"%@", weakObj);
        };
        block();
    }
    return 0;
}
