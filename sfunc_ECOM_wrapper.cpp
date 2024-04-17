
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
#include <custom_keysave.h>
#include <osrng.h>
#include <rsa.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 88

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
void sfunc_ECOM_Outputs_wrapper(const uint8_T *ecom_input_name,
			uint8_T *ecom_output)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
using namespace CryptoPP;
    AutoSeededRandomPool rng;
    
    //Convert from uint8 Array to string
    std::string input_str = (char *) ecom_input_name;
    RSA::PublicKey publicKey;
    std::string ecom_data = "ECOM Data Encryption Test", cipher_data;
    if(input_str == "GSE1"){
        //Load key
        LoadPublicKey("rsa-public.key", publicKey);
        // Encryption
        RSAES_OAEP_SHA_Encryptor e(publicKey);

        StringSource ss1(ecom_data, true,
            new PK_EncryptorFilter(rng, e,
            new StringSink(cipher_data)
            ) // PK_EncryptorFilter
        ); // StringSource
        //Convert string to uint8 Array        
        for (size_t i = 0; i < cipher_data.size(); ++i) {
            ecom_output[i] = static_cast<uint8_t>(cipher_data[i]);
        }
    }//if
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


