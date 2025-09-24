from flask import Flask, jsonify

app = Flask(__name__)

# Dummy blockchain for explorer
blockchain = [
    {"index": 0, "hash": "genesis", "transactions": [{"to": "VRX_FOUNDER", "amount": 1000000}]}
]

@app.route("/blocks")
def get_blocks():
    return jsonify(blockchain)

@app.route("/add_block/<hash>")
def add_block(hash):
    blockchain.append({"index": len(blockchain), "hash": hash, "transactions": []})
    return jsonify({"status": "added", "hash": hash})

if __name__ == "__main__":
    app.run(port=5000)
