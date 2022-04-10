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
class BasicGainAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    BasicGainAudioProcessorEditor (BasicGainAudioProcessor&);
    ~BasicGainAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Slider mGainSlider;


    BasicGainAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicGainAudioProcessorEditor)
};
