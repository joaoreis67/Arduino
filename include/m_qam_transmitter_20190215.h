# ifndef M_QAM_TRANSMITTER_H_
# define M_QAM_TRANSMITTER_H_

# include "netxpto_20190215.h"

# include "binary_source_20190215.h"
# include "m_qam_mapper_20190215.h"
# include "discrete_to_continuous_time_20190215.h"
# include "pulse_shaper_20190215.h"
# include "iq_modulator_20190215.h"
# include "super_block_interface_20190215.h"

//using namespace std;


class MQamTransmitter : public SuperBlock {

	/* State Variables */

	// #####################################################################################################
	// ################## Internal Signals Declaration and Inicialization ##################################
	// #####################################################################################################

	Binary S1{ "MQAM01.sgn" };

	TimeDiscreteAmplitudeDiscreteReal S2{ "MQAM02.sgn" };

	TimeDiscreteAmplitudeDiscreteReal S3{ "MQAM03.sgn" };

	TimeContinuousAmplitudeDiscreteReal S4{ "MQAM04.sgn" };

	TimeContinuousAmplitudeDiscreteReal S5{ "MQAM05.sgn" };

	TimeContinuousAmplitudeContinuousReal S6{ "MQAM06.sgn" };

	TimeContinuousAmplitudeContinuousReal S7{ "MQAM07.sgn" };

	// S8 reserved for laser if necessary in the future

	OpticalSignal S9{ "MQAM09.sgn", 0 };
	OpticalSignalXY S9_xy{ "MQAM09_xy.sgn", 0 };

	Binary S10{ "MQAM10.sgn" };

	OpticalSignal S11{ "MQAM11.sgn", 0 };
	OpticalSignalXY S11_xy{ "MQAM11_xy.sgn", 0 };

	Binary S12{ "MQAM12.sgn" };

	// #####################################################################################################
	// ########################### Blocks Declaration and Inicialization ###################################
	// #####################################################################################################


	BinarySource B1;

	MQamMapper B2;

	DiscreteToContinuousTime B3;

	DiscreteToContinuousTime B4;

	PulseShaper B5;

	PulseShaper B6;

	IqModulator B7;

	SuperBlockInterface B8;

	/* Input Parameters */



public:

	/* Methods */

	MQamTransmitter(vector<Signal *> &inputSignal, vector<Signal *> &outputSignal);

	/* Set Methods */

	void set(int opt);

	void setMode(BinarySourceMode m) { B1.setMode(m); };
	BinarySourceMode const getMode(void) { return B1.getMode(); };

	void setProbabilityOfZero(double pZero) { B1.setProbabilityOfZero(pZero); };
	double const getProbabilityOfZero(void) { return B1.getProbabilityOfZero(); };

	void setBitStream(string bStream) { B1.setBitStream(bStream); };
	string const getBitStream(void) { return B1.getBitStream(); };

	void setNumberOfBits(long int nOfBits) { B1.setNumberOfBits(nOfBits); }
	long int const getNumberOfBits(void) { return B1.getNumberOfBits();  }

	void setPatternLength(int pLength) { B1.setPatternLength(pLength); }
	int const getPatternLength(void) { return B1.getPatternLength(); }

	void setBitPeriod(double bPeriod) {B1.setBitPeriod(bPeriod);};
	double const getBitPeriod(void) { return B1.getBitPeriod(); }

	void setM(int mValue){B2.m = mValue;};
	int const getM(void) { return B2.m; };

	void setIqAmplitudes(vector<t_iqValues> iqAmplitudesValues){ B2.m = iqAmplitudesValues.size(); B2.iqAmplitudes.resize(B2.m); B2.iqAmplitudes = iqAmplitudesValues; };
	vector<t_iqValues> const getIqAmplitudes(void){ return B2.iqAmplitudes; };

	void setNumberOfSamplesPerSymbol(int n){ B3.setNumberOfSamplesPerSymbol(n); B4.setNumberOfSamplesPerSymbol(n); };
	int const getNumberOfSamplesPerSymbol(void){ return B3.getNumberOfSamplesPerSymbol(); };

	void setRollOffFactor(double rOffFactor){ B5.setRollOffFactor(rOffFactor); B6.setRollOffFactor(rOffFactor); };
	double const getRollOffFactor(void){ return B5.getRollOffFactor(); };

	void setSeeBeginningOfImpulseResponse(bool sBeginningOfImpulseResponse){ B5.setSeeBeginningOfImpulseResponse(sBeginningOfImpulseResponse); B6.setSeeBeginningOfImpulseResponse(sBeginningOfImpulseResponse); };
	double const getSeeBeginningOfImpulseResponse(void){ return B5.getSeeBeginningOfImpulseResponse(); };

	void setOutputOpticalPower(t_real outOpticalPower) { B7.outputOpticalPower = outOpticalPower; };
	t_real const getOutputOpticalPower(void) { return B7.outputOpticalPower; };

	void setOutputOpticalPower_dBm(t_real outOpticalPower_dBm) { B7.setOutputOpticalPower_dBm(outOpticalPower_dBm); };
	t_real const getOutputOpticalPower_dBm(void) { return 10*log10(B7.outputOpticalPower/1e-3); }

	void setPulseShaperFilter(PulseShaperFilter fType){ B5.setFilterType(fType); B6.setFilterType(fType); };
	PulseShaperFilter const getPulseShaperFilter(void) { return B5.getFilterType(); };

	void usePassiveFilterMode(bool pFilterMode) { B5.usePassiveFilterMode(pFilterMode); B6.usePassiveFilterMode(pFilterMode); }

	void setImpulseResponseFilename(string fName) { B5.setImpulseResponseFilename(fName); B6.setImpulseResponseFilename(fName); }
	
	void setDirName(string newDirName);
	string getDirName(void) { return dirName; }

	private:

		string dirName{ "" };
};

#endif
