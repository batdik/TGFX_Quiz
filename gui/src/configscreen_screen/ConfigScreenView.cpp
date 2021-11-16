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
    touchgfx::Unicode::itoa(cfg.MinAngle, _lowerStr, 10, 10);
    touchgfx::Unicode::itoa(cfg.MaxAngle, _upperStr, 10, 10);
  
    lowerBoundaries.setWildcard(_lowerStr);
    upperBoundaries.setWildcard(_upperStr);
    upperBoundaries.invalidate();
    lowerBoundaries.invalidate();

    sliderSetAngle.setValue(presenter->getAngle());  
}

void ConfigScreenView::tearDownScreen()
{
    ConfigScreenViewBase::tearDownScreen();
}

void ConfigScreenView::handleTickEvent() {
    touchgfx::Unicode::itoa(sliderSetAngle.getValue(), _angleValueStr, 10, 10);
    rampAngle.setWildcard(_angleValueStr);
    rampAngle.invalidate();
}

void ConfigScreenView::saveAnglaValue()
{
   presenter->setAngle(sliderSetAngle.getValue());
}
