#include "RangeProof.h"

// Default constructor: Initializes proof data to zero
RangeProof::RangeProof() : proofLength(0) {
    proof.fill(0);
}

// Constructor from a vector of bytes and length
RangeProof::RangeProof(const std::vector<uint8_t>& proofData, size_t length) : proofLength(length) {
    std::copy_n(proofData.begin(), std::min(proofData.size(), MAX_PROOF_SIZE), proof.begin());
}

// Returns the internal proof data
const std::array<uint8_t, RangeProof::MAX_PROOF_SIZE>& RangeProof::getProof() const {
    return proof;
}

// Returns the length of the proof
size_t RangeProof::getProofLength() const {
    return proofLength;
}

// Verifies the range proof for a given commitment
bool RangeProof::verify(Secp256k1Wrapper& secp, const Commitment& commit) {
    return secp.verifyRangeProof(commit.getData(), proof, proofLength);
}
