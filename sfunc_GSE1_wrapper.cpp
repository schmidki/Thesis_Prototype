
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <string>
#include <rsa.h>
#include <osrng.h>
#include <custom_keysave.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 64

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void sfunc_GSE1_Outputs_wrapper(const uint8_T *gse_input,
			uint8_T *gse_output_name)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
//Convert from uint8 Array to string
    std::string input_str = (char *) gse_input;
    //Check for Valid Command
    if (input_str == "requestValidCertificate"){
        using namespace CryptoPP;
        ////////////////////////////////////////////////
        // Generate keys
        AutoSeededRandomPool rng;
        
        InvertibleRSAFunction params;
        params.GenerateRandomWithKeySize(rng, 700);
        
        RSA::PrivateKey privateKey(params);
        RSA::PublicKey publicKey(params);
        SavePrivateKey("rsa-private.key", privateKey);
        SavePublicKey("rsa-public.key", publicKey);
        
        //Output name
        std::string output_str = "GSE1";
        std::copy(output_str.begin(), output_str.end(), gse_output_name);
    }
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


