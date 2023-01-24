# UIA-Repro
Testing UIA repro for problems

# Checkbox UIA Test
In this minimal UIA app, the window is treated as one UIA fragment, which has the `CheckBox` role and provides the `Toggle` pattern. Its state is always `indeterminate`. When hovering the cursor over it with NVDA active, I would expect to hear something like "Fragment root - checkbox - indeterminate", or anything to indicate that the fragment is a checkbox and has a toggled state. Instead, I only hear "Fragment root" (the name of the fragment).
