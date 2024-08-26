#ifndef RANGEPROOF_H
#define RANGEPROOF_H

#include <array>
#include <vector>
#include "Secp256k1Wrapper.h"

// RangeProof class representing a range proof for a Pedersen commitment
class RangeProof {
public:
    static constexpr size_t MAX_PROOF_SIZE = 5134;  // Maximum size of a range proof

    // Default constructor
    RangeProof();

    // Constructor from a vector of bytes and length
    RangeProof(const std::vector<uint8_t>& proofData, size_t length);

    // Returns the proof data
    const std::array<uint8_t, MAX_PROOF_SIZE>& getProof() const;

    // Returns the length of the proof
    size_t getProofLength() const;

    // Verifies the range proof for a given commitment
    bool verify(Secp256k1Wrapper& secp, const Commitment& commit);

private:
    std::array<uint8_t, MAX_PROOF_SIZE> proof;  // Internal proof data
    size_t proofLength;  // Length of the proof
};

#endif // RANGEPROOF_H
