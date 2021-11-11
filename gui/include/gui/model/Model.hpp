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

protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
