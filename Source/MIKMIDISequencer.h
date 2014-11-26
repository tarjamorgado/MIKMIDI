//
//  MIKMIDISequencer.h
//  MIKMIDI
//
//  Created by Chris Flesner on 11/26/14.
//  Copyright (c) 2014 Mixed In Key. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>

@class MIKMIDISequence;
@class MIKMIDIMetronome;


@interface MIKMIDISequencer : NSObject

+ (instancetype)sequencer;

- (instancetype)initWithSequence:(MIKMIDISequence *)sequence;
+ (instancetype)sequencerWithSequence:(MIKMIDISequence *)sequence;

@property (strong, nonatomic) MIKMIDISequence *sequence;
@property (readonly, nonatomic) BOOL isPlaying;
@property (readonly, nonatomic) BOOL isRecording;

@property (nonatomic) MusicTimeStamp currentTimeStamp;
@property (nonatomic) MusicTimeStamp preRoll;

@property (nonatomic) MusicTimeStamp punchInTime;
@property (nonatomic) MusicTimeStamp punchOutTime;

@property (nonatomic, getter=isLooping) BOOL looping;
@property (nonatomic) MusicTimeStamp loopStartTimeStamp;
@property (nonatomic) MusicTimeStamp loopEndTimeStamp;

@property (strong, nonatomic) MIKMIDIMetronome *metronome;
@property (nonatomic, getter=isClickTrackAlwaysEnabled) BOOL clickTrackAlwaysEnabled;
@property (nonatomic, getter=isClickTrackEnabledInRecord) BOOL clickTrackEnabledInRecord;
@property (nonatomic, getter=isClickTrackEnabledInPreRoll) BOOL clickTrackEnabledInPreRoll;

@property (copy, nonatomic) NSSet *recordEnabledTracks;

- (void)startPlayback;
- (void)startPlaybackAtTimeStamp:(MusicTimeStamp)timeStamp;
- (void)startPlaybackAtTimeStamp:(MusicTimeStamp)timeStamp MIDITimeStamp:(MIDITimeStamp)midiTimeStamp;
- (void)resumePlayback;
- (void)stopPlayback;

- (void)startRecording;
- (void)startRecordingAtTimeStamp:(MusicTimeStamp)timeStamp;
- (void)startRecordingAtTimeStamp:(MusicTimeStamp)timeStamp MIDITimeStamp:(MIDITimeStamp)midiTimeStamp;
- (void)resumeRecording;
- (void)stopRecording;

- (void)recordMIDICommands:(NSSet *)commands;

@end
