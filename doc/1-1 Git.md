# SCM, SVN, and Git

Before diving into Git, it is important to understand the basics of **version control**.

- **SCM (Source Code Management)**: SCM is a system that records changes to a file or a set of files over time. It allows you to track history, see who made changes, and go back to older versions if you make a mistake. It is essential for teamwork.
- **SVN (Subversion)**: SVN is a **Centralized** Version Control System. This means all the code history is stored on one single central server. Developers must connect to this server to save or download updates. If the central server goes down, no one can save their work.
- **Git**: Git is a **Distributed** Version Control System. Instead of relying on one central server, every developer downloads a complete, local copy of the entire project history to their own computer. It is much faster, allows you to work offline, and is much safer because everyone has a backup.

## Git Architecture

To use Git properly, you need to understand how it handles files.

Git moves your files through three different "zones" on your computer:

1. **Working Directory**: This is your actual project folder. It is where you create, edit, and delete files.
2. **Staging Area**: This is a waiting room. When you are happy with your changes, you move the files here to prepare them for saving.
3. **Local Repository**: This is Git's database on your computer. When you save the files from the staging area, they are permanently recorded here.

### Common Git Commands

- `git clone <link>`: Downloads a complete copy of a project from the internet.
- `git status`: Shows you the current state of your files (e.g., which files are new or changed).
- `git add <file>`: Moves a file from the Working Directory to the Staging Area.
- `git commit -m "message"`: Saves the staged files into your Local Repository with a short message describing the changes.
- `git push`: Sends your local saved changes up to a remote server (like GitHub).
- `git pull`: Downloads the newest changes from a remote server to your local computer.
- `git config user.name "name"` & `git config user.email "email"`: Sets your identity. Git requires you to tell it who you are before you can save any changes.

## GitHub, GitLab, Bitbucket, and GitHub Enterprise

People often confuse Git and GitHub. **Git** is the tool you install on your computer. **GitHub** is a website that hosts your Git projects (Remote Repositories) so you can share them with others.

- **GitHub**: The most popular public platform for hosting code. It is the home of millions of open-source projects.
- **GitLab**: A platform very similar to GitHub, famous for its excellent built-in CI/CD tools.
- **Bitbucket**: Atlassian's Git platform, deeply integrated with Jira and Confluence.
- **GitHub Enterprise**: The paid, corporate version of GitHub with advanced security and admin tools. Can be installed on a company's own private servers.

## Markdown Overview

Markdown is a lightweight, easy-to-learn markup language that uses simple symbols to format plain text. It has become a standard for digital writing, and is heavily used in the AI world for writing prompts and defining AI Agent skills.

Syntax cheat sheet: <https://www.markdownguide.org/cheat-sheet/>

## Verified on machine (WSL2, Ubuntu 24.04)

The three-area workflow, observed by editing this very repo:

```
$ git status --short                       # Working Directory clean
                                           # (empty = nothing changed)

$ echo "note" >> "doc/1-1 Git.md"          # edit a file
$ git status --short
 M doc/1-1 Git.md                          # M (red) = modified, NOT yet staged

$ git add "doc/1-1 Git.md"                 # move Working Dir -> Staging
$ git status --short
M  doc/1-1 Git.md                          # M (green) = staged, ready to commit

$ git diff --staged                        # what is in the Staging Area
diff --git a/doc/1-1 Git.md ...
+note

$ git commit -m "msg"                      # Staging -> Local Repository
$ git push                                 # Local Repo -> Remote (GitHub)
```

The color flip from red `M` to green `M` after `git add` is the file moving
from the Working Directory into the Staging Area — the three-zone model made
visible.

## Practice

1. [x] Sign up for a GitHub account.
2. [x] Create a repository in your account.
3. [x] Install Git and VS Code on your PC.
4. [x] Clone the new repository to your PC and open it via VS Code.
5. [x] Write your first Markdown note (Learn Git) in VS Code.
6. [x] Push it to GitHub once completed.
