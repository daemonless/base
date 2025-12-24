# base-image

The core base image for all native FreeBSD OCI containers in the Daemonless project.

## Overview

This image provides a minimal FreeBSD environment optimized for containers. It includes a custom initialization system based on **s6** to manage process lifecycle and environment configuration.

## Features

- **s6 Supervision**: Standardized process management and reaping.
- **PUID/PGID Support**: Map the internal `bsd` user to your host user IDs for seamless volume permissions.
- **VNET Ready**: Configured to work with Virtual Network stacks.
- **Multiple OS Support**: Variants available for FreeBSD 14 and 15.
- **Package Selection**: Supports both `latest` and `quarterly` FreeBSD package branches.

## Environment Variables

| Variable | Default | Description |
|----------|---------|-------------|
| `PUID` | 1000 | User ID for the `bsd` user. |
| `PGID` | 1000 | Group ID for the `bsd` user. |
| `TZ` | UTC | Container timezone. |

## Usage (for Image Developers)

Use this as the base for your own FreeBSD images:

```dockerfile
FROM ghcr.io/daemonless/base-image:15

# Install your app
RUN pkg install -y myapp

# Add your init scripts
COPY root/ /

# Enable your service
RUN ln -sf /etc/services.d/myapp/run /run/s6/services/myapp/run
```

## Directory Structure

- `/init`: The main entrypoint script.
- `/etc/cont-init.d/`: Place initialization scripts here (executed once at startup).
- `/etc/services.d/`: Place service definitions here (supervised by s6).
- `/custom-cont-init.d/`: Mount a volume here to run your own startup scripts without rebuilding the image.

## Variants

- `ghcr.io/daemonless/base-image:15` (FreeBSD 15.x)
- `ghcr.io/daemonless/base-image:14` (FreeBSD 14.x)
- Suffix `-quarterly` for images using the stable quarterly package branch.
<!-- Trigger build -->
