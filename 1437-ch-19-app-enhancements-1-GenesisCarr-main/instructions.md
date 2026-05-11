# Labs 19–22: Grade Calculator — UX Enhancement Sprints

## Overview

Over the next four labs, you will **iteratively improve** the user experience of your Grade Calculator from Lab 18. Each lab is a **sprint** — you pick one or more enhancements, implement them, test them by running the program, and push your work. There is no single "correct" solution; the goal is to make your calculator genuinely pleasant and robust to use.

Your final Grade Calculator (after Lab 22) will be evaluated as part of your **Final Project**, along with a **User Guide** (`USER_GUIDE.md`) that you will write in your repository.

## How These Labs Work

**Each lab follows the same agile cycle:**

1. **Plan** — Pick 1–3 enhancements from the feature menu below (or propose your own)
2. **Implement** — Write the code in `main.cpp` (you may also add new `.h` files if needed)
3. **Test** — Run the program and try to break your own feature. Enter bad input. Try edge cases.
4. **Commit & Push** — Your code must compile cleanly to receive credit
5. **Reflect** — In your commit message, briefly note what you added and why

You do **not** need to implement everything in one sprint. Small, working improvements each week are better than a large broken change. This is how professional software is built.

## Automated Testing

Unlike Lab 18, these labs use **compile-only tests**. Your grade for each sprint is based on:

| Test | Points | What It Checks |
|------|--------|----------------|
| Compilation | 100 | Code compiles with `g++ -std=c++17` without errors |

Your UX enhancements will be evaluated by your instructor as part of the Final Project.

## Feature Menu

Choose from these categories. You are also welcome to invent your own features — creativity counts.

### Input Validation & Error Handling
- Reject non-numeric input (e.g., typing "abc" when a number is expected) without crashing
- Prevent negative points or points earned exceeding points possible
- Add confirmation prompts for destructive actions ("Are you sure you want to remove this item?")
- Handle empty-list edge cases gracefully (e.g., "No items to display" instead of a blank table)

### Display & Formatting
- Add color using ANSI escape codes (e.g., green for A, red for F)
- Add a dashboard/summary that shows at a glance: total items, items per category, current grade
- Improve the table layout (borders, alignment, category grouping)
- Add a "clear screen" option or auto-clear between menu actions for cleaner output
- Display a progress bar or visual grade indicator

### New Functionality
- **Edit an item** — change the name, score, or category of an existing item
- **Sort items** — by name, category, percentage, or date added
- **Search/filter** — find items by name or show only one category
- **Save/Load** — write items to a file and reload them next session (file I/O)
- **Undo** — reverse the last add or remove action
- **GPA calculation** — convert letter grades to GPA scale
- **Statistics** — show min, max, median, standard deviation across items
- **"What-if" analysis** — "What score do I need on the final to get a B?"

### Code Quality
- Break large functions into smaller helper functions
- Add meaningful comments explaining your design decisions
- Use constants instead of magic numbers
- Improve variable naming for clarity

## Sprint Planning Tips

**Sprint 1 (Lab 19):** Start with input validation. A calculator that crashes on bad input isn't usable. This is low-hanging fruit with high impact.

**Sprint 2 (Lab 20):** Add a feature that makes the app more useful — save/load, editing, or search. Pick something you would actually want if you were using this tool.

**Sprint 3 (Lab 21):** Polish the display. Add color, better formatting, or a dashboard. First impressions matter.

**Sprint 4 (Lab 22):** Final polish. Fix any rough edges, add your `USER_GUIDE.md`, and make sure everything works together. This is your release candidate.

These are suggestions, not requirements. Adapt your plan based on what you learn each sprint.

## User Guide (Due with Final Project)

By Lab 22, your repository must include a file called `USER_GUIDE.md` in the root directory. This is a simple markdown document that explains:

1. **What the program does** — a brief description
2. **How to compile and run it** — the exact command(s)
3. **How to use each feature** — walk through the menu options, especially any features you added
4. **Known limitations** — anything that doesn't work perfectly (honesty is valued)

This does not need to be long — 1 to 2 pages is fine. Write it for a user who has never seen your program before.

## What "Done" Looks Like

After four sprints, your Grade Calculator should:

- **Not crash** on any input — bad numbers, empty input, out-of-range selections
- **Be intuitive** — a new user can figure out the menu without reading source code
- **Have at least 4–6 enhancements** beyond the Lab 18 baseline
- **Compile cleanly** with `g++ -std=c++17`
- **Include a User Guide** (`USER_GUIDE.md`)

## Tips

- **Commit often.** Each feature should be its own commit. If something breaks, you can roll back.
- **Test with bad input.** Type letters when it expects numbers. Enter 0 items then try to calculate. Enter negative scores. Your program should handle all of it.
- **Keep it compiling.** A feature that doesn't compile earns zero points for the sprint. Get something small working before adding complexity.
- **Read your own output.** Run the program and pretend you've never seen it before. Is it clear what to do? Are the results easy to read?