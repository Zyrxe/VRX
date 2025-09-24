cd ~/path/to/vrxcoin

# Inisialisasi git
git init
git branch -M main

# Tambah remote repository
git remote add origin https://github.com/<username>/vrxcoin.git

# Tambah semua file
git add .

# Commit pertama
git commit -m "Initial commit: VRX blockchain PoW"

# Push ke GitHub
git push -u origin main
