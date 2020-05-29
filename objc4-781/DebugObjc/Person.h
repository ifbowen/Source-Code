//
//  Person.h
//  DebugObjc
//
//  Created by Bowen on 2020/5/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject

+ (void)run;

- (void)sleep;

@end

@interface Person (ext)

- (void)eat;

@end

NS_ASSUME_NONNULL_END
