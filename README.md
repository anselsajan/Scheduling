# Scheduling

# CPU Scheduling Algorithms in C

This project implements two popular *CPU scheduling algorithms* — *First Come First Serve (FCFS)* and *Shortest Job First (SJF - Non-Preemptive)* — using the C programming language. It allows the user to enter process details and view the computed scheduling results including waiting time, turnaround time, and completion time.

---

## 💻 Features

- Input support for multiple processes.
- Selection of scheduling algorithm:
  - First Come First Serve (FCFS)
  - Shortest Job First (SJF - Non-Preemptive)
- Displays:
  - Completion Time
  - Waiting Time
  - Turnaround Time
- Computes average waiting and turnaround times.

---

## 📂 File Structure
 📁 cpu-scheduling
│
├── scheduling.c     # Main C program
├── README.md        # Project description

## 🛠️ How to Run

### 🧱 Requirements:
- GCC compiler or any C compiler installed.

### 🏃 Steps:
1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/cpu-scheduling.git
   cd cpu-scheduling
   
 2.	Compile the code:
     gcc scheduling.c -o scheduling
 3.	Run the program:
    ./scheduling

    
 📷 Sample Output
Enter number of processes: 3
Process 1 Arrival Time: 0
Process 1 Burst Time: 5
Process 2 Arrival Time: 1
Process 2 Burst Time: 3
Process 3 Arrival Time: 2
Process 3 Burst Time: 8

Choose Scheduling Algorithm:
1. First Come First Serve (FCFS)
2. Shortest Job First (SJF - Non Preemptive)
Enter choice: 1

--- FCFS Scheduling ---
PID     Arrival Burst   Completion      Waiting Turnaround
1       0       5       5               0       5
2       1       3       8               4       7
3       2       8       16              6       14

Average Waiting Time: 3.33
Average Turnaround Time: 8.67

 ✍️ Author
 Ansel Sajan
