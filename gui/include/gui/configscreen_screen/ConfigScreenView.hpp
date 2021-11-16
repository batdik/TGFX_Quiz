#ifndef CONFIGSCREENVIEW_HPP
#define CONFIGSCREENVIEW_HPP

#include <gui_generated/configscreen_screen/ConfigScreenViewBase.hpp>
#include <gui/configscreen_screen/ConfigScreenPresenter.hpp>

class ConfigScreenView : public ConfigScreenViewBase
{
public:
    ConfigScreenView();
    virtual ~ConfigScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    void handleTickEvent() final;
    virtual void saveAnglaValue();
	
private:
    touchgfx::Unicode::UnicodeChar _lowerStr[10];
    touchgfx::Unicode::UnicodeChar _upperStr[10];
    touchgfx::Unicode::UnicodeChar _angleValueStr[10];
};

#endif // CONFIGSCREENVIEW_HPP
