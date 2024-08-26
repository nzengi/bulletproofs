#include "Secp256k1Wrapper.h"
#include "Commitment.h"
#include "RangeProof.h"
#include <iostream>

int main() {
    // Initialize secp256k1 context wrapper
    Secp256k1Wrapper secp;

    // Example usage and test
    try {
        // Public key data (replace with actual public key data)
        std::vector<uint8_t> pubKeyData = {/* Public key bytes */};
        PublicKey pubKey(pubKeyData);

        // Create commitment from public key
        Commitment commit = Commitment::fromPubKey(secp, pubKey);
        std::cout << "Commitment created from public key." << std::endl;

        // Example range proof data (replace with actual proof data)
        std::vector<uint8_t> proofData = {/* Proof bytes */};
        RangeProof proof(proofData, proofData.size());

        // Verify range proof
        if (proof.verify(secp, commit)) {
            std::cout << "Range proof verified successfully." << std::endl;
        } else {
            std::cout << "Range proof verification failed." << std::endl;
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
