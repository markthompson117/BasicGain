/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BasicGainAudioProcessorEditor::BasicGainAudioProcessorEditor (BasicGainAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    mGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);

    mGainSlider.setRange(0.0f, 1.0f, 0.01f);
    mGainSlider.setValue(0.8f);
    addAndMakeVisible(mGainSlider);

    setSize (400, 300);
}

BasicGainAudioProcessorEditor::~BasicGainAudioProcessorEditor()
{
}

//==============================================================================
void BasicGainAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void BasicGainAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
