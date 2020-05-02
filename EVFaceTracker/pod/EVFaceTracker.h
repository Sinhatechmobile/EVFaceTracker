//
//  EVFaceTracker.h
//
//  Created by Edwin Vermeer on 3/13/12.
//  Copyright (c) 2012. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreImage/CoreImage.h>
#import <UIKit/UIKit.h>
@protocol EVFaceTrackerDelegate <NSObject>
- (void)faceIsTracked:(CGRect)faceRect withOffsetWidth:(float)offsetWidth andOffsetHeight:(float)offsetHeight andDistance:(float) distance;
- (void)fluentUpdateDistance:(float)distance;
- (void)capturedImage:(UIImage *)image;
@end


API_AVAILABLE(ios(10.0))
@interface EVFaceTracker : NSObject <AVCaptureVideoDataOutputSampleBufferDelegate, AVCapturePhotoCaptureDelegate> {
    AVCapturePhotoOutput *stillImageOutput;
    AVCaptureVideoDataOutput *videoDataOutput;
    AVCaptureVideoPreviewLayer *previewLayer;
    dispatch_queue_t videoDataOutputQueue;
    CIDetector *faceDetector;
    CGRect faceRect;
    float reactionFactor;
    float distance;
    float previousDistance;
    float updateInterval;
}

@property (nonatomic, unsafe_unretained, readwrite) id <EVFaceTrackerDelegate> delegate;
@property (nonatomic, assign, readwrite) CGRect faceRect;
@property (nonatomic, assign, readwrite) float reactionFactor;
@property (nonatomic, assign, readwrite) float updateInterval;

- (id)initWithDelegate:(id)theDelegate;
- (void)fluidUpdateInterval:(float)interval withReactionFactor:(float) factor;
- (void)addPreviewView:(UIView *)view;
- (void)captureImage;
@end
