Here’s a comprehensive guide to the most commonly used commands in the `nano` text editor. `nano` is a simple, user-friendly text editor in Unix/Linux systems, perfect for quick edits. It opens files in a terminal window and provides a variety of shortcut commands for easy navigation and editing.

---

## **Basic Commands**

1. **Opening a File**
   ```bash
   nano filename
   ```
   - If the file doesn’t exist, `nano` will create it.

2. **Exiting nano**
   - **`Ctrl + X`**: Exits `nano`. If there are unsaved changes, it will prompt you to save or discard them.

3. **Saving a File**
   - **`Ctrl + O`** (Write Out): Saves the current file without exiting.
   - **Enter**: After `Ctrl + O`, pressing Enter will confirm the filename.

---

## **Basic Editing Commands**

1. **Cutting Text**
   - **`Ctrl + K`**: Cuts the current line and saves it to a buffer.
   
2. **Pasting Text**
   - **`Ctrl + U`**: Pastes the last cut text at the cursor position.

3. **Copying Text**
   - **`Ctrl + Shift + 6`** (or `Ctrl + ^`): Sets a mark at the cursor position to start selecting text.
   - **Arrow Keys**: Move the cursor to highlight the desired text.
   - **`Ctrl + K`**: After selecting, this copies the highlighted text to the buffer.

4. **Undo/Redo**
   - **`Alt + U`**: Undo the last action.
   - **`Alt + E`**: Redo the last undone action.

---

## **Navigational Commands**

1. **Moving the Cursor**
   - **Arrow Keys**: Move the cursor up, down, left, and right.
   - **`Ctrl + A`**: Move to the beginning of the current line.
   - **`Ctrl + E`**: Move to the end of the current line.
   - **`Ctrl + Y`**: Move up one screen.
   - **`Ctrl + V`**: Move down one screen.

2. **Moving to Specific Positions**
   - **`Ctrl + _`**: Jump to a specific line and column. Enter the line and column numbers, then press Enter.

3. **Scrolling**
   - **`Ctrl + Y`**: Scroll up one page.
   - **`Ctrl + V`**: Scroll down one page.

---

## **Searching and Replacing Text**

1. **Find Text**
   - **`Ctrl + W`** (Where Is): Prompts for a search term, then searches forward from the cursor position.

2. **Repeat Search**
   - **`Ctrl + W`** + Enter: Finds the next instance of the search term.

3. **Search and Replace**
   - **`Ctrl + \`**: Prompts for the search term, then the replacement term, and allows you to confirm each replacement with `Y` or `N`.

---

## **File and Buffer Commands**

1. **Opening Another File**
   - **`Ctrl + R`** (Read File): Opens another file within the current nano session.

2. **Inserting Another File**
   - After pressing `Ctrl + R`, enter the filename to insert its contents at the cursor position.

3. **Switching Between Buffers**
   - **`Ctrl + X`** to close the current file, then reopen the desired buffer with **`Ctrl + R`**.

---

## **Indentation and Alignment**

1. **Auto-Indent New Lines**
   - **`Alt + I`**: Toggles auto-indent on or off.

2. **Indent and Unindent Text**
   - **`Ctrl + Shift + ]`**: Indents the selected text.
   - **`Ctrl + Shift + [`**: Unindents the selected text.

---

## **Special Commands and Shortcuts**

1. **View Help**
   - **`Ctrl + G`**: Opens the help menu in `nano` with a list of commands.

2. **Spell Check**
   - **`Ctrl + T`**: Starts a spell check on the document (if spell-checking is enabled and `spell` or `aspell` is installed).

3. **Toggling Features**
   - **`Alt + X`**: Toggles syntax highlighting (if available).
   - **`Alt + L`**: Toggles line numbering.

---

## **Useful Tips**

1. **Creating New Files in nano**
   - If you type `nano newfile.txt` and the file doesn’t exist, nano will create it when you save your edits.

2. **Disabling Line Wrapping**
   - Start nano with the `-w` option:
     ```bash
     nano -w filename
     ```
   - This disables line wrapping, making it easier to edit configuration files.

3. **Opening Files in Read-Only Mode**
   - **`Ctrl + R`**: Use `nano -v filename` to view a file without making changes.
  
4. **Executing a Command Within nano**
   - **`Ctrl + R`** followed by **`Ctrl + X`**: Allows you to execute a command and insert its output directly into your document.

---

## **Summary Table of Key Commands**

| Command                | Description                                   |
|------------------------|-----------------------------------------------|
| `Ctrl + O`             | Save file                                     |
| `Ctrl + X`             | Exit nano                                     |
| `Ctrl + K`             | Cut line                                      |
| `Ctrl + U`             | Paste                                         |
| `Ctrl + Shift + 6`     | Start selecting text                          |
| `Ctrl + A` / `Ctrl + E`| Move to beginning/end of the line             |
| `Ctrl + W`             | Search for text                               |
| `Ctrl + \`             | Search and replace text                       |
| `Ctrl + T`             | Spell check                                   |
| `Ctrl + G`             | Display help                                  |
| `Ctrl + _`             | Go to a specific line                         |
| `Alt + U` / `Alt + E`  | Undo / Redo                                   |

These commands cover the basics and advanced functionalities in `nano` to help you edit files efficiently.
