#include "ML_modules.hpp"


struct Constants : Module {
	enum ParamIds {
		NUM_PARAMS
	};
	enum InputIds {
		NUM_INPUTS
	};
	enum OutputIds {
		P_1_OUTPUT,
		P_2_OUTPUT,
		P_3_OUTPUT,
		P_4_OUTPUT,
		P_5_OUTPUT,
		P_7_OUTPUT,
		P_12_OUTPUT,
		M_1_OUTPUT,
		M_2_OUTPUT,
		M_3_OUTPUT,
		M_4_OUTPUT,
		M_5_OUTPUT,
		M_7_OUTPUT,
		M_12_OUTPUT,
		NUM_OUTPUTS
	};
	enum LightIds {
		NUM_LIGHTS
	};

#ifdef v040
	Constants() : Module( NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS ) {};
#endif

#ifdef v_dev
	Constants() : Module( NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS ) {};
#endif

	void step() override;

};



void Constants::step() {

	double semi = 1.0/12.0;

	outputs[P_1_OUTPUT].value  = semi;
	outputs[P_2_OUTPUT].value  = 2*semi;
	outputs[P_3_OUTPUT].value  = 3*semi;
	outputs[P_4_OUTPUT].value  = 4*semi;
	outputs[P_5_OUTPUT].value  = 5*semi;
	outputs[P_7_OUTPUT].value  = 7*semi;
	outputs[P_12_OUTPUT].value = 1.0;

	outputs[M_1_OUTPUT].value  = - semi;
	outputs[M_2_OUTPUT].value  = - 2*semi;
	outputs[M_3_OUTPUT].value  = - 3*semi;
	outputs[M_4_OUTPUT].value  = - 4*semi;
	outputs[M_5_OUTPUT].value  = - 5*semi;
	outputs[M_7_OUTPUT].value  = - 7*semi;
	outputs[M_12_OUTPUT].value = - 1.0;

};



ConstantsWidget::ConstantsWidget() {

	Constants *module = new Constants();
	setModule(module);
	box.size = Vec(15*6, 380);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin,"res/Constants.svg")));

		addChild(panel);
	}

	addChild(createScrew<ScrewSilver>(Vec(15, 0)));
	addChild(createScrew<ScrewSilver>(Vec(15, 365)));




	const float offset_y = 65, delta_y = 40, offset_xL=10, offset_xR=55;


	for(int i=0; i<7; i++) {

		addOutput(createOutput<PJ301MPort>(Vec(offset_xR, offset_y + i*delta_y), module, Constants::P_1_OUTPUT + i));
		addOutput(createOutput<PJ301MPort>(Vec(offset_xL, offset_y + i*delta_y), module, Constants::M_1_OUTPUT + i));

	};


}
