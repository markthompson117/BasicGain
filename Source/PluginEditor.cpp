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
    mGainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);

    mGainSlider.setRange(0.0f, 1.0f, 0.01f);
    mGainSlider.setValue(0.8f);

    mGainSlider.addListener(this);

    addAndMakeVisible(mGainSlider);

    setSize (400, 300);
}

BasicGainAudioProcessorEditor::~BasicGainAudioProcessorEditor()
{
}

//==============================================================================
void BasicGainAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkgrey);
}

void BasicGainAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds();
    bounds.removeFromTop(getHeight() / 2);
    bounds.removeFromBottom(25);  //JUCE_LIVE_CONSTANT(10)
    bounds.removeFromLeft(20);
    bounds.removeFromRight(20);

    mGainSlider.setBounds(bounds);
}

void BasicGainAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    if (slider == &mGainSlider)
    {
        audioProcessor.mGain = mGainSlider.getValue();      //we have done it from the slider input to the method, not specifically mGainSlider, still works "slider->getValue()"
    }
}