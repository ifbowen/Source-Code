//
//  Person.m
//  DebugObjc
//
//  Created by Bowen on 2020/5/26.
//

#import "Person.h"

@implementation Person

+ (void)run
{
    Person *p = [[Person alloc] init];
    [p eat];
    [p eat];
}

- (void)sleep
{
    [self eat];
}

@end

@implementation Person (ext)

- (void)eat
{
    NSLog(@"%s", __func__);
}

@end
