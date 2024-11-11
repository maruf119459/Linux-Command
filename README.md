Here's a comprehensive guide to commonly used **`vi`** commands, covering navigation, editing, searching, saving, and more. **`vi`** (and its enhanced version, **`vim`**) is a powerful text editor widely used in Unix-like systems.

---

## **Starting vi**

```bash
vi filename
```

This command opens **`vi`** with the specified file. If the file doesn’t exist, **`vi`** will create it upon saving.

---

## **Modes in vi**

**`vi`** operates in three primary modes:

1. **Normal Mode**: Default mode for navigation and basic commands.
2. **Insert Mode**: Mode to insert or edit text.
3. **Command Mode**: Mode to execute commands (e.g., saving, quitting).

To switch modes:

- **Normal Mode**: Press `Esc` to exit to Normal mode.
- **Insert Mode**: Press `i`, `I`, `a`, `A`, `o`, or `O`.
- **Command Mode**: Press `:` while in Normal mode.

---

## **Basic Navigation Commands (Normal Mode)**

| Command | Description                                       |
|---------|---------------------------------------------------|
| `h`     | Move cursor left                                  |
| `j`     | Move cursor down                                  |
| `k`     | Move cursor up                                    |
| `l`     | Move cursor right                                 |
| `0`     | Move to beginning of the line                     |
| `$`     | Move to end of the line                           |
| `w`     | Move to the beginning of the next word            |
| `b`     | Move to the beginning of the previous word        |
| `G`     | Move to the end of the file                       |
| `gg`    | Move to the beginning of the file                 |
| `:n`    | Go to line number `n`                             |

---

## **Inserting and Editing Text**

To enter Insert mode:

| Command | Description                                       |
|---------|---------------------------------------------------|
| `i`     | Insert before the cursor                          |
| `I`     | Insert at the beginning of the line               |
| `a`     | Append after the cursor                           |
| `A`     | Append at the end of the line                     |
| `o`     | Open a new line below and start editing           |
| `O`     | Open a new line above and start editing           |

---

## **Deleting Text**

| Command  | Description                                       |
|----------|---------------------------------------------------|
| `x`      | Delete character under the cursor                 |
| `X`      | Delete character before the cursor                |
| `dw`     | Delete from the cursor to the end of the word     |
| `d$`     | Delete from the cursor to the end of the line     |
| `dd`     | Delete the entire current line                    |
| `D`      | Delete the entire line from the cursor position   |

---

## **Copying, Cutting, and Pasting Text**

| Command  | Description                                       |
|----------|---------------------------------------------------|
| `yy`     | Copy (yank) the entire line                       |
| `yw`     | Copy (yank) the current word                      |
| `y$`     | Copy (yank) to the end of the line                |
| `p`      | Paste after the cursor                            |
| `P`      | Paste before the cursor                           |
| `dd`     | Cut (delete) the entire line                      |
| `dw`     | Cut (delete) the current word                     |
| `d$`     | Cut (delete) from the cursor to end of the line   |

---

## **Undo and Redo Changes**

| Command | Description                                       |
|---------|---------------------------------------------------|
| `u`     | Undo the last change                              |
| `Ctrl + r` | Redo the last undone change                    |

---

## **Searching and Replacing Text**

| Command                        | Description                                                   |
|--------------------------------|---------------------------------------------------------------|
| `/text`                        | Search for `text` forward                                     |
| `?text`                        | Search for `text` backward                                    |
| `n`                            | Move to the next occurrence of the search term                |
| `N`                            | Move to the previous occurrence of the search term            |
| `:%s/old/new/g`                | Replace all occurrences of `old` with `new` in the file       |
| `:%s/old/new/gc`               | Replace all occurrences with confirmation                     |

---

## **Saving and Exiting**

| Command      | Description                                           |
|--------------|-------------------------------------------------------|
| `:w`         | Save changes                                          |
| `:w filename`| Save to a specified filename                          |
| `:q`         | Quit                                                  |
| `:q!`        | Quit without saving changes                           |
| `:wq` or `ZZ`| Save changes and quit                                 |
| `:x`         | Save and exit (only if changes were made)             |
| `:w!`        | Force save if the file is read-only                   |
| `:wq!`       | Force save and quit if the file is read-only          |

---

## **Window Management**

| Command       | Description                                              |
|---------------|----------------------------------------------------------|
| `:split`      | Split window horizontally                                |
| `:vsplit`     | Split window vertically                                  |
| `Ctrl + w` + `w` | Toggle between split windows                         |
| `:close`      | Close the current split window                           |
| `:resize n`   | Resize the window to `n` lines                           |

---

## **Marking and Jumping to Text**

Marks allow you to mark a specific position and return to it later.

| Command      | Description                                            |
|--------------|--------------------------------------------------------|
| `m[a-z]`     | Set a mark (for example, `ma` sets mark `a`)           |
| `'a`         | Jump to mark `a`                                       |
| `''`         | Jump back to the previous cursor position              |

---

## **Advanced Editing Commands**

| Command            | Description                                      |
|--------------------|--------------------------------------------------|
| `>>`               | Indent the current line                          |
| `<<`               | Unindent the current line                        |
| `>}`               | Indent from the cursor to the end of the paragraph |
| `J`                | Join the current line with the next line         |

---

## **Visual Mode (Selecting Text)**

| Command | Description                                                |
|---------|------------------------------------------------------------|
| `v`     | Enter visual mode, select text character by character      |
| `V`     | Enter visual line mode, select entire lines                |
| `Ctrl + v` | Enter visual block mode, select text in columns         |
| `y`     | Yank (copy) selected text                                  |
| `d`     | Delete selected text                                       |
| `>`     | Indent selected text                                       |
| `<`     | Unindent selected text                                     |

---

## **Configuration and Customization**

- **Open `.vimrc` for customization**:
    ```bash
    vi ~/.vimrc
    ```
    You can configure **`vi`/`vim`** settings here, such as setting line numbers, enabling syntax highlighting, or customizing indentation.

- **Useful `.vimrc` Settings**:
    ```vim
    set number             " Show line numbers
    syntax on              " Enable syntax highlighting
    set tabstop=4          " Set tab width to 4 spaces
    set shiftwidth=4       " Set indentation width to 4 spaces
    set expandtab          " Use spaces instead of tabs
    ```

---

## Summary Table of Commands

| Category             | Commands                                         |
|----------------------|--------------------------------------------------|
| **Navigation**       | `h`, `j`, `k`, `l`, `0`, `$`, `G`, `gg`         |
| **Insert Mode**      | `i`, `I`, `a`, `A`, `o`, `O`                    |
| **Delete**           | `x`, `dd`, `dw`, `d$`, `D`                      |
| **Copy & Paste**     | `yy`, `yw`, `y$`, `p`, `P`                      |
| **Undo & Redo**      | `u`, `Ctrl + r`                                 |
| **Search & Replace** | `/text`, `:%s/old/new/g`, `:%s/old/new/gc`      |
| **Save & Quit**      | `:w`, `:q`, `:wq`, `:q!`, `:w!`, `:wq!`         |
| **Window Management**| `:split`, `:vsplit`, `Ctrl + w` + `w`, `:close` |
| **Marks**            | `m[a-z]`, `'a`, `''`                            |
| **Advanced Editing** | `>>`, `<<`, `J`                                 |
| **Visual Mode**      | `v`, `V`, `Ctrl + v`, `y`, `d`, `>`, `<`        |

---

This guide should equip you with essential commands to efficiently use **`vi`** for editing, navigation, and file management in Linux. Each command helps streamline tasks and enhances productivity for command-line editing.
