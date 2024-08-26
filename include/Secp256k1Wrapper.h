#ifndef SECP256K1WRAPPER_H
#define SECP256K1WRAPPER_H

#include <array>
#include "secp256k1.h"  // secp256k1 library headers
#include "secp256k1_rangeproof.h"

class PublicKey;  // Forward declaration

class Secp256k1Wrapper {
public:
    Secp256k1Wrapper();
    ~Secp256k1Wrapper();

    // Converts a public key to a Pedersen commitment
    bool pubKeyToPedersenCommitment(std::array<uint8_t, 33>& out, const PublicKey& pk);

    // Converts a Pedersen commitment back to a public key
    PublicKey pedersenCommitmentToPubKey(const std::array<uint8_t, 33>& commit);

    // Verifies a range proof for a given commitment
    bool verifyRangeProof(const std::array<uint8_t, 33>& commit, const std::array<uint8_t, 5134>& proof, size_t proofLength);

private:
    secp256k1_context* ctx;  // Context for secp256k1 operations
};

#endif // SECP256K1WRAPPER_H
