//
//  main.m
//  Debug-block
//
//  Created by BowenCoder on 2019/11/10.
//

#import <Foundation/Foundation.h>

/*
 史上最详细的Block源码剖析
 https://www.jianshu.com/p/d96d27819679
 */
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSObject *obj = [[NSObject alloc] init];
        void (^block)(void) = ^{
            NSLog(@"%@", obj);
        };
        block();
    }
    return 0;
}
