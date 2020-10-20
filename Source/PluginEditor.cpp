/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BasicDistortionAudioProcessorEditor::BasicDistortionAudioProcessorEditor (BasicDistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 200);
     
    // OUTPUT
    // these define the parameters of our slider object
    outputSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    outputSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
    outputSlider.setRange (-50.0f, 0.0f, 0.5f);
    outputSlider.setValue(0.0f);
    // this = this class
    outputSlider.addListener(this);
    // slider customization
    outputSlider.getLookAndFeel().setColour(juce::Slider::thumbColourId, juce::Colours::red);
    outputSlider.getLookAndFeel().setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkred);
     
    // this function adds the slider to the editor
    addAndMakeVisible (&outputSlider);
    
    outputValue = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, OUTPUT_ID, outputSlider);
    
    
    // Drive
    driveSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    driveSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
    driveSlider.setRange (1.f, 25.0f, 0.05f);
    driveSlider.setValue(1.f);
    driveSlider.addListener(this);

    driveSlider.getLookAndFeel().setColour(juce::Slider::thumbColourId, juce::Colours::red);
    driveSlider.getLookAndFeel().setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkred);
     
    addAndMakeVisible (&driveSlider);
    
    driveValue = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DRIVE_ID, driveSlider);
    
    
    // input
    inputSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    inputSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
    inputSlider.setRange (-30.0f, 30.0f, 0.5f);
    inputSlider.setValue(0.0f);
    inputSlider.addListener(this);

    inputSlider.getLookAndFeel().setColour(juce::Slider::thumbColourId, juce::Colours::red);
    inputSlider.getLookAndFeel().setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkred);
     
    addAndMakeVisible (&inputSlider);
    
    inputValue = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, INPUT_ID, inputSlider);
}

BasicDistortionAudioProcessorEditor::~BasicDistortionAudioProcessorEditor()
{
}

//==============================================================================
void BasicDistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    
    g.setFont (20.0f);
     
    g.drawFittedText ("Input", -110, 20, getWidth(), 30, juce::Justification::centred, 1);
    g.drawFittedText("Drive", 0, 20, getWidth(), 30, juce::Justification::centred, 1);
    g.drawFittedText("Output", 110, 20, getWidth(), 30, juce::Justification::centred, 1);
    
}

void BasicDistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    inputSlider.setBounds(40-15, getHeight()/4, 130, 130);
    driveSlider.setBounds(140-5, getHeight()/4, 130, 130);
    outputSlider.setBounds(240+5, getHeight()/4, 130, 130);
}

void BasicDistortionAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
//    if (slider == &outputSlider)
//    {
//        audioProcessor.output = outputSlider.getValue();
//    }
//    else if (slider == &driveSlider)
//    {
//        audioProcessor.drive = driveSlider.getValue();
//    }
//    else if (slider ==&inputSlider)
//    {
//        audioProcessor.input = inputSlider.getValue();
//    }
}
