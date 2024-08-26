#include "Commitment.h"
#include <algorithm>
#include <stdexcept>

// Default constructor: Initializes commitment data to zero
Commitment::Commitment() {
    data.fill(0);
}

// Constructor from a vector of bytes
Commitment::Commitment(const std::vector<uint8_t>& vec) {
    std::copy_n(vec.begin(), std::min(vec.size(), COMMITMENT_SIZE), data.begin());
}

// Creates a commitment from a public key using secp256k1
Commitment Commitment::fromPubKey(Secp256k1Wrapper& secp, const PublicKey& pk) {
    std::array<uint8_t, COMMITMENT_SIZE> commit_i;
    if (secp.pubKeyToPedersenCommitment(commit_i, pk)) {
        return Commitment(commit_i);
    } else {
        throw std::runtime_error("Failed to create commitment from public key");
    }
}

// Converts the commitment back to a public key
PublicKey Commitment::toPubKey(Secp256k1Wrapper& secp) const {
    return secp.pedersenCommitmentToPubKey(data);
}

// Returns the internal commitment data
const std::array<uint8_t, Commitment::COMMITMENT_SIZE>& Commitment::getData() const {
    return data;
}
