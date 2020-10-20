/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class BasicDistortionAudioProcessorEditor  : public juce::AudioProcessorEditor,
public juce::Slider::Listener
{
public:
    BasicDistortionAudioProcessorEditor (BasicDistortionAudioProcessor&);
    ~BasicDistortionAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged (juce::Slider* sliderGain) override;
    
    juce::Slider driveSlider;
    juce::Slider mixSlider;
    juce::Slider outputSlider;
    juce::Slider inputSlider;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BasicDistortionAudioProcessor& audioProcessor;
    
public:
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> outputValue;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> inputValue;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> driveValue;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicDistortionAudioProcessorEditor)
};
