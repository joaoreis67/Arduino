# ifndef PROGRAM_INCLUDE_PHASE_MISMATCH_COMPENSATION_H_
# define PROGRAM_INCLUDE_PHASE_MISMATCH_COMPENSATION_H_


# include "netxpto_20180815.h"

# include <complex>
# include <random>
# include <vector>

enum PhaseCompensationMode { SequentialMode, DelayLineMode };

class PhaseMismatchCompensation : public Block {

	/* State Variables */


	/* Input Parameters */

	int pilotRate = 2;
	int numberOfSamplesForEstimation = 2;

	bool firstRun = true;
	long int auxP = 0;
	long int auxQ = 0;
	long int count = 0;
	double wrap = 0;
	double phaseBefore;
	double phase;

	PhaseCompensationMode mode{ SequentialMode };

	vector<t_complex> samplesForEstimation;
	vector<t_complex> delayLine;

public:

	/* Methods */
	PhaseMismatchCompensation(initializer_list<Signal *> InputSig, initializer_list<Signal *> OutputSig) :Block(InputSig, OutputSig) {};

	void initialize(void);
	bool runBlock(void);

	void setPilotRate(int pRate) { pilotRate = pRate; }
	double getPilotRate() { return pilotRate; }

	void setMode(PhaseCompensationMode m) { mode = m; }
	PhaseCompensationMode const getMode(void) { return mode; }

};

#endif 
