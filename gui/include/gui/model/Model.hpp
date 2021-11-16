#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

namespace Config {
	struct MainConfig_t;
	struct ConfigConfig_t;
}

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
	

	const Config::MainConfig_t& getMainConfig() const;
	const Config::ConfigConfig_t& getConfigConfig() const;
  
    const int& getAngleValue() const;
    void setAngleValue(int _angleValue);

protected:
    ModelListener* modelListener;

    int _angleValue = 25;
};

#endif // MODEL_HPP
