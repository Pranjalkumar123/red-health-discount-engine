# Red Health: Smart Discount Allocation Engine

## 💡 Problem Statement
Distribute a fixed discount kitty fairly among sales agents based on:
- Performance Score
- Seniority
- Target Achievement
- Active Clients

## 🚀 Approach
Each attribute is normalized to a 0–1 scale, then combined using weighted scoring:
- Performance: 40%
- Target Achieved: 30%
- Seniority: 20%
- Active Clients: 10%

The discount kitty is then divided proportionally based on these scores.

## 🧪 Test Cases Included
- ✅ Equal Scores (Fair split)
- ✅ Rounding Edge Case (Sum equals kitty)
- ✅ Normal Case (Varied performance)

## ⚙️ How to Run

### 📂 Run Main Program:
1. Make sure you have `json.hpp` in the project folder (from [nlohmann/json](https://github.com/nlohmann/json))
2. Compile and Run:
   ```bash
   g++ main.cpp allocator.cpp -o allocator
   ./allocator
   Run Tests:

3.Compile test file:

g++ test.cpp allocator.cpp -o test
./test 

Thoughts

This solution ensures fairness, scalability, and readability. It is built modularly for future logic updates.

👤 Author

Developed by Pranjal Kumar
NIT Jamshedpur | CSE | 2026 Batch

🔒 Access

Access given to GitHub username: red-911
Deadline: 6th August (EoD)

