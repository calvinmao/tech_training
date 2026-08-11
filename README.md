# tech_training

My practice for the Avaya DLBBEWIKI Foundation Training (1-1 Git, 1-2 GCC, 1-3 FD, 1-4 MM).

## Layout

```
.
├── doc/
│   ├── 1-1 Git.md
│   ├── 1-2 GCC.md
│   ├── 1-3 FD.md
│   └── 1-4 MM.md
└── src/
    ├── loop.c        # 1-2 GCC: infinite loop for process observation
    ├── mycat.c       # 1-3 FD:  a simplified cat using open/read/write/close
    └── memleak.c     # 1-4 MM:  a memory leak that triggers the OOM Killer
```

## Build

```bash
gcc src/loop.c    -o loop
gcc src/mycat.c   -o mycat
gcc src/memleak.c -o memleak
```

## Run

```bash
# 1-2 GCC: watch a process consume CPU
./loop &; top -p $!; kill $!

# 1-3 FD: a custom cat
./mycat /etc/hosts
ls -l /proc/$$/fd   # see your own stdin/stdout/stderr (0/1/2)

# 1-4 MM: trigger the OOM Killer (WARNING: will be killed by the kernel)
./memleak
```
