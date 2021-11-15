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
};

#endif // CONFIGSCREENVIEW_HPP
