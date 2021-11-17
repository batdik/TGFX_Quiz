#include <gui/configscreen_screen/ConfigScreenView.hpp>
#include "gui/common/Configuration.hpp"

ConfigScreenView::ConfigScreenView()
{
}

void ConfigScreenView::setupScreen()
{
    ConfigScreenViewBase::setupScreen();
	
    auto & cfg = presenter->getConfig();

    sliderSetAngle.setValueRange(cfg.MinAngle, cfg.MaxAngle);
    touchgfx::Unicode::itoa(cfg.MinAngle, _lowerStr, StrSize, 10);
    touchgfx::Unicode::itoa(cfg.MaxAngle, _upperStr, StrSize, 10);
  
    lowerBoundaries.setWildcard(_lowerStr);
    upperBoundaries.setWildcard(_upperStr);
    upperBoundaries.invalidate();
    lowerBoundaries.invalidate();

    sliderSetAngle.setValue(presenter->getAngle());  
    handleTickEvent();
}

void ConfigScreenView::tearDownScreen()
{
    ConfigScreenViewBase::tearDownScreen();
}

void ConfigScreenView::handleTickEvent() {
    if (lastAngleValue == sliderSetAngle.getValue())
        return;

    lastAngleValue = sliderSetAngle.getValue();
    touchgfx::Unicode::itoa(lastAngleValue, _angleValueStr, StrSize, 10);
    rampAngle.setWildcard(_angleValueStr);
    rampAngle.invalidate();
}

void ConfigScreenView::saveAnglaValue()
{
   presenter->setAngle(lastAngleValue);
}
