/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import "AIRMapCallout.h"

#import <MapKit/MapKit.h>
#import <UIKit/UIKit.h>

#import <React/RCTConvert+MapKit.h>
#import <React/RCTComponent.h>
#import "AIRMap.h"
#import "SMCalloutView.h"

@class RCTBridge;

@interface AIRMapMarker : MKAnnotationView <MKAnnotation>

struct ImportantStatus {
    BOOL isImportant;
    float unimportantOpacity;
};
typedef struct ImportantStatus ImportantStatus;

@property (nonatomic, strong) AIRMapCallout *calloutView;
@property (nonatomic, weak) AIRMap *map;
@property (nonatomic, weak) RCTBridge *bridge;

@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, copy) NSString *imageSrc;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subtitle;
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;
@property (nonatomic, strong) UIColor *pinColor;
@property (nonatomic, assign) NSInteger zIndex;
// TODO: Do something about this, its hacky
@property (nonatomic, copy) NSString *dotColor;
/**
 * TODO: Move to subclass AheadMarker
 */
//@property (nonatomic, assign) BOOL isImportant;
//@property (nonatomic, assign) float unimportantOpacity;
@property (nonatomic, assign) ImportantStatus importantStatus;
@property (nonatomic, assign) float radius;


@property (nonatomic, copy) RCTBubblingEventBlock onPress;
@property (nonatomic, copy) RCTDirectEventBlock onSelect;
@property (nonatomic, copy) RCTDirectEventBlock onDeselect;
@property (nonatomic, copy) RCTDirectEventBlock onCalloutPress;
@property (nonatomic, copy) RCTDirectEventBlock onDragStart;
@property (nonatomic, copy) RCTDirectEventBlock onDrag;
@property (nonatomic, copy) RCTDirectEventBlock onDragEnd;


- (MKAnnotationView *)getAnnotationView;
- (void)fillCalloutView:(SMCalloutView *)calloutView;
- (BOOL)shouldShowCalloutView;
- (void)showCalloutView;
- (void)hideCalloutView;
- (BOOL)shouldUsePinView;
- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event;

@end


@interface AIREmptyCalloutBackgroundView : SMCalloutBackgroundView
@end
