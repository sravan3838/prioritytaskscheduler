# Priority Task Scheduler

A C-based task management system that prioritizes tasks using deadlines, importance, duration, and a Max Heap.

## Features

- Add, display, search, update, complete, and delete tasks
- Validate Task IDs, importance, duration, and deadlines
- Calculate task priority using:
  - Importance Score
  - Urgency Score
  - Lead-Time Risk
- Identify overdue tasks
- Retrieve the highest-priority pending task
- Sort tasks using Merge Sort
- Save and load tasks using file handling
- Generate productivity reports

## Priority Formula

**Importance Score**
`Importance × 20`

**Urgency Score**
`100 / (1 + Days Remaining)`

**Lead-Time Risk**
`min(2, Duration / Hours Remaining) × 50`

**Priority**
`Importance Score + Urgency Score + Lead-Time Risk`

Maximum priority = **300**

## Data Structures & Algorithms

- **Array** – stores tasks
- **Linear Search** – searches tasks by ID
- **Max Heap** – retrieves highest-priority task
- **Merge Sort** – sorts tasks by priority
- **Structures** – represents task data
- **File Handling** – stores persistent task data


├── file.h / file.c
├── analytics.h / analytics.c
└── tasks.txt
