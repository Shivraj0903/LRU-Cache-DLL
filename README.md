# 🧠 LRU Cache (Least Recently Used Cache)

This project implements an **LRU Cache** (Least Recently Used Cache) using **C++**.  
It efficiently stores and retrieves data with **O(1)** time complexity for both `get()` and `put()` operations, using a combination of a **Doubly Linked List** and an **unordered_map**.

---

## 🚀 Features

- ⚡ **O(1)** time complexity for both `get()` and `put()`  
- 🧩 Uses a **Doubly Linked List** for maintaining usage order  
- 🗺️ Uses **unordered_map** for fast key lookups  
- 🧹 Automatically removes the least recently used (LRU) item when capacity is full  
- 🧪 Well-structured and clean C++ implementation

---

## 🧩 How It Works

- The cache maintains two data structures:
  1. **Doubly Linked List** → to keep track of the usage order (most recently used at the front)
  2. **unordered_map** → to store key–node mappings for O(1) access

- When a key is accessed (`get()`), it moves to the **front** of the list.  
- When a new key is added (`put()`):
  - If the cache is full, the **least recently used** key (at the end of the list) is removed.
  - The new key is inserted at the **front**.

---

## 🧠 Time & Space Complexity

| Operation | Time Complexity | Space Complexity |
|------------|-----------------|------------------|
| `get()`    | O(1)            | O(capacity)      |
| `put()`    | O(1)            | O(capacity)      |

---


