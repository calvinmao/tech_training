# Learn Git — Basic Commands

A practical reference for the most common Git commands, organized by what you're trying to do.

> **Prerequisite:** Install Git from <https://git-scm.com/downloads>, then configure your identity once:
>
> ```bash
> git config --global user.name  "Your Name"
> git config --global user.email "you@example.com"
> git config --global init.defaultBranch main
> ```

---

## 1. Setup & Initialization

| Command | Description |
|---------|-------------|
| `git init` | Create a new local repository in the current folder |
| `git clone <url>` | Copy a remote repository to your machine |
| `git clone <url> my-folder` | Clone into a custom folder name |
| `git status` | Show working tree status (changed/staged files) |

**Start a brand-new project:**

```bash
mkdir my-project && cd my-project
git init
git status
```

---

## 2. Staging & Committing

Git uses a **two-step** workflow: *stage* changes, then *commit* them.

| Command | Description |
|---------|-------------|
| `git add <file>` | Stage a specific file |
| `git add .` | Stage all changes in the current directory |
| `git add -A` | Stage all changes (including deletes) across the repo |
| `git commit -m "message"` | Commit staged changes with a message |
| `git commit -am "message"` | Stage tracked files **and** commit in one step |
| `git rm <file>` | Remove a file and stage the deletion |
| `git mv <old> <new>` | Rename/move a file and stage it |

**Example:**

```bash
git add README.md
git commit -m "docs: add project README"
```

---

## 3. Inspecting History & Changes

| Command | Description |
|---------|-------------|
| `git status` | What's changed / staged / untracked |
| `git diff` | Unstaged changes |
| `git diff --staged` | Changes that are staged but not committed |
| `git log` | Full commit history |
| `git log --oneline --graph` | Compact visual history |
| `git show <commit>` | Details of a specific commit |
| `git blame <file>` | Who changed each line, and when |

```bash
git log --oneline --graph --all
```

---

## 4. Branching & Merging

Branches let you work on features without affecting `main`.

| Command | Description |
|---------|-------------|
| `git branch` | List local branches (`*` = current) |
| `git branch <name>` | Create a new branch |
| `git switch <name>` | Switch to a branch |
| `git switch -c <name>` | Create **and** switch in one step |
| `git checkout <name>` | Older syntax to switch branches |
| `git merge <branch>` | Merge `<branch>` into the current branch |
| `git branch -d <name>` | Delete a merged branch |
| `git branch -D <name>` | Force-delete a branch |

**Typical feature workflow:**

```bash
git switch -c feature/login
# ...make changes, commit...
git switch main
git merge feature/login
git branch -d feature/login
```

---

## 5. Remote Repositories (GitHub / GitLab / Bitbucket)

| Command | Description |
|---------|-------------|
| `git remote -v` | List configured remotes |
| `git remote add origin <url>` | Link a remote named `origin` |
| `git fetch` | Download remote changes **without** merging |
| `git pull` | `fetch` + `merge` (update local branch) |
| `git push` | Upload local commits to the remote |
| `git push -u origin main` | Push and set upstream (first time only) |
| `git remote remove origin` | Unlink a remote |

**First push to a new GitHub repo:**

```bash
git remote add origin https://github.com/user/repo.git
git branch -M main
git push -u origin main
```

---

## 6. Undoing Changes

| Command | Description |
|---------|-------------|
| `git restore <file>` | Discard local changes in a file |
| `git restore --staged <file>` | Unstage a file (keep the changes) |
| `git commit --amend` | Edit the last commit's message/contents |
| `git reset --soft HEAD~1` | Undo last commit, keep changes staged |
| `git reset --mixed HEAD~1` | Undo last commit, keep changes unstaged (default) |
| `git reset --hard HEAD~1` | ⚠️ Undo last commit **and discard** changes |
| `git revert <commit>` | Create a new commit that undoes a previous one (safe for shared branches) |

> ⚠️ `git reset --hard` permanently discards work. Use `git revert` on branches others may be using.

---

## 7. Stashing (Shelving Work Temporarily)

| Command | Description |
|---------|-------------|
| `git stash` | Save uncommitted changes and clean the working tree |
| `git stash list` | Show all stashes |
| `git stash pop` | Reapply the most recent stash and remove it |
| `git stash apply` | Reapply a stash but keep it in the list |
| `git stash drop` | Discard the most recent stash |

```bash
git stash
git switch main
git switch -       # back to previous branch
git stash pop
```

---

## 8. Tags (Marking Releases)

| Command | Description |
|---------|-------------|
| `git tag` | List all tags |
| `git tag v1.0.0` | Create a lightweight tag |
| `git tag -a v1.0.0 -m "Release 1.0"` | Create an annotated tag |
| `git push origin v1.0.0` | Push a tag to the remote |
| `git push --tags` | Push all tags |

---

## 9. Ignoring Files

Create a **`.gitignore`** file to exclude files from version control.

```gitignore
# .gitignore example
node_modules/
*.log
.env
dist/
__pycache__/
.vscode/
```

Already tracked a file you want to ignore? Untrack it first:

```bash
git rm --cached <file>
```

---

## 10. Common Daily Workflow

```bash
# 1. Get the latest changes
git pull

# 2. Create a feature branch
git switch -c feature/my-change

# 3. Make edits, then stage & commit
git add .
git commit -m "feat: add new feature"

# 4. Push the branch
git push -u origin feature/my-change

# 5. Open a Pull Request on GitHub/GitLab, get it reviewed & merged
```

---

## Quick Cheat Sheet

```
init      → start a repo
clone     → copy a repo
add       → stage changes
commit    → save a snapshot
status    → see what changed
log       → view history
branch    → list/create branches
switch    → change branches
merge     → combine branches
pull      → fetch + merge from remote
push      → send commits to remote
restore   → undo local changes
stash     → shelve work temporarily
```

---

## Further Reading

- Official book (free): <https://git-scm.com/book/en/v2>
- Interactive tutorial: <https://learngitbranching.js.org>
- GitHub Docs: <https://docs.github.com/en/get-started>
- Visual Git reference: <https://marklodato.github.io/visual-git-guide/index-en.html>
