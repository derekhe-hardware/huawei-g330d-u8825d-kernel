/* Copyright (c) 2008-2012, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _SPI_QSD_H
#define _SPI_QSD_H

#define SPI_DRV_NAME                  "spi_qsd"

#if defined(CONFIG_SPI_QSD) || defined(CONFIG_SPI_QSD_MODULE)

#define QSD_REG(x) (x)
#define QUP_REG(x)

#define SPI_FIFO_WORD_CNT             0x0048

#else

#define QSD_REG(x)
#define QUP_REG(x) (x)

#define QUP_CONFIG                    0x0000 /* N & NO_INPUT/NO_OUPUT bits */
#define QUP_ERROR_FLAGS_EN            0x030C
#define QUP_ERR_MASK                  0x3
#define SPI_OUTPUT_FIFO_WORD_CNT      0x010C
#define SPI_INPUT_FIFO_WORD_CNT       0x0214
#define QUP_MX_WRITE_COUNT            0x0150
#define QUP_MX_WRITE_CNT_CURRENT      0x0154

#define QUP_CONFIG_SPI_MODE           0x0100
#endif

#define GSBI_CTRL_REG                 0x0
#define GSBI_SPI_CONFIG               0x30
#define QUP_HARDWARE_VER              0x0030
#define QUP_OPERATIONAL_MASK          0x0028
#define QUP_ERROR_FLAGS               0x0308

#define SPI_CONFIG                    QSD_REG(0x0000) QUP_REG(0x0300)
#define SPI_IO_CONTROL                QSD_REG(0x0004) QUP_REG(0x0304)
#define SPI_IO_MODES                  QSD_REG(0x0008) QUP_REG(0x0008)
#define SPI_SW_RESET                  QSD_REG(0x000C) QUP_REG(0x000C)
#define SPI_TIME_OUT_CURRENT          QSD_REG(0x0014) QUP_REG(0x0014)
#define SPI_MX_OUTPUT_COUNT           QSD_REG(0x0018) QUP_REG(0x0100)
#define SPI_MX_OUTPUT_CNT_CURRENT     QSD_REG(0x001C) QUP_REG(0x0104)
#define SPI_MX_INPUT_COUNT            QSD_REG(0x0020) QUP_REG(0x0200)
#define SPI_MX_INPUT_CNT_CURRENT      QSD_REG(0x0024) QUP_REG(0x0204)
#define SPI_MX_READ_COUNT             QSD_REG(0x0028) QUP_REG(0x0208)
#define SPI_MX_READ_CNT_CURRENT       QSD_REG(0x002C) QUP_REG(0x020C)
#define SPI_OPERATIONAL               QSD_REG(0x0030) QUP_REG(0x0018)
#define SPI_ERROR_FLAGS               QSD_REG(0x0034) QUP_REG(0x001C)
#define SPI_ERROR_FLAGS_EN            QSD_REG(0x0038) QUP_REG(0x0020)
#define SPI_DEASSERT_WAIT             QSD_REG(0x003C) QUP_REG(0x0310)
#define SPI_OUTPUT_DEBUG              QSD_REG(0x0040) QUP_REG(0x0108)
#define SPI_INPUT_DEBUG               QSD_REG(0x0044) QUP_REG(0x0210)
#define SPI_TEST_CTRL                 QSD_REG(0x004C) QUP_REG(0x0024)
#define SPI_OUTPUT_FIFO               QSD_REG(0x0100) QUP_REG(0x0110)
#define SPI_INPUT_FIFO                QSD_REG(0x0200) QUP_REG(0x0218)
#define SPI_STATE                     QSD_REG(SPI_OPERATIONAL) QUP_REG(0x0004)

/* SPI_CONFIG fields */
#define SPI_CFG_INPUT_FIRST           0x00000200
#define SPI_NO_INPUT                  0x00000080
#define SPI_NO_OUTPUT                 0x00000040
#define SPI_CFG_LOOPBACK              0x00000100
#define SPI_CFG_N                     0x0000001F

/* SPI_IO_CONTROL fields */
#define SPI_IO_C_FORCE_CS             0x00000800
#define SPI_IO_C_CLK_IDLE_HIGH        0x00000400
#define SPI_IO_C_MX_CS_MODE           0x00000100
#define SPI_IO_C_CS_N_POLARITY        0x000000F0
#define SPI_IO_C_CS_N_POLARITY_0      0x00000010
#define SPI_IO_C_CS_SELECT            0x0000000C
#define SPI_IO_C_TRISTATE_CS          0x00000002
#define SPI_IO_C_NO_TRI_STATE         0x00000001

/* SPI_IO_MODES fields */
#define SPI_IO_M_OUTPUT_BIT_SHIFT_EN  QSD_REG(0x00004000) QUP_REG(0x00010000)
#define SPI_IO_M_PACK_EN              QSD_REG(0x00002000) QUP_REG(0x00008000)
#define SPI_IO_M_UNPACK_EN            QSD_REG(0x00001000) QUP_REG(0x00004000)
#define SPI_IO_M_INPUT_MODE           QSD_REG(0x00000C00) QUP_REG(0x00003000)
#define SPI_IO_M_OUTPUT_MODE          QSD_REG(0x00000300) QUP_REG(0x00000C00)
#define SPI_IO_M_INPUT_FIFO_SIZE      QSD_REG(0x000000C0) QUP_REG(0x00000380)
#define SPI_IO_M_INPUT_BLOCK_SIZE     QSD_REG(0x00000030) QUP_REG(0x00000060)
#define SPI_IO_M_OUTPUT_FIFO_SIZE     QSD_REG(0x0000000C) QUP_REG(0x0000001C)
#define SPI_IO_M_OUTPUT_BLOCK_SIZE    QSD_REG(0x00000003) QUP_REG(0x00000003)

#define INPUT_BLOCK_SZ_SHIFT          QSD_REG(4)          QUP_REG(5)
#define INPUT_FIFO_SZ_SHIFT           QSD_REG(6)          QUP_REG(7)
#define OUTPUT_BLOCK_SZ_SHIFT         QSD_REG(0)          QUP_REG(0)
#define OUTPUT_FIFO_SZ_SHIFT          QSD_REG(2)          QUP_REG(2)
#define OUTPUT_MODE_SHIFT             QSD_REG(8)          QUP_REG(10)
#define INPUT_MODE_SHIFT              QSD_REG(10)         QUP_REG(12)

/* SPI_OPERATIONAL fields */
#define SPI_OP_MAX_INPUT_DONE_FLAG    0x00000800
#define SPI_OP_MAX_OUTPUT_DONE_FLAG   0x00000400
#define SPI_OP_INPUT_SERVICE_FLAG     0x00000200
#define SPI_OP_OUTPUT_SERVICE_FLAG    0x00000100
#define SPI_OP_INPUT_FIFO_FULL        0x00000080
#define SPI_OP_OUTPUT_FIFO_FULL       0x00000040
#define SPI_OP_IP_FIFO_NOT_EMPTY      0x00000020
#define SPI_OP_OP_FIFO_NOT_EMPTY      0x00000010
#define SPI_OP_STATE_VALID            0x00000004
#define SPI_OP_STATE                  0x00000003

#define SPI_OP_STATE_CLEAR_BITS       0x2
enum msm_spi_state {
	SPI_OP_STATE_RESET = 0x00000000,
	SPI_OP_STATE_RUN   = 0x00000001,
	SPI_OP_STATE_PAUSE = 0x00000003,
};

/* SPI_ERROR_FLAGS fields */
#define SPI_ERR_OUTPUT_OVER_RUN_ERR   0x00000020
#define SPI_ERR_INPUT_UNDER_RUN_ERR   0x00000010
#define SPI_ERR_OUTPUT_UNDER_RUN_ERR  0x00000008
#define SPI_ERR_INPUT_OVER_RUN_ERR    0x00000004
#define SPI_ERR_CLK_OVER_RUN_ERR      0x00000002
#define SPI_ERR_CLK_UNDER_RUN_ERR     0x00000001

/* We don't allow transactions larger than 4K-64 or 64K-64 due to
   mx_input/output_cnt register size */
#define SPI_MAX_TRANSFERS             QSD_REG(0xFC0) QUP_REG(0xFC0)
#define SPI_MAX_LEN                   (SPI_MAX_TRANSFERS * dd->bytes_per_word)

#define SPI_NUM_CHIPSELECTS           4
#define SPI_SUPPORTED_MODES  (SPI_CPOL | SPI_CPHA | SPI_CS_HIGH | SPI_LOOP)

#define SPI_DELAY_THRESHOLD           1
/* Default timeout is 10 milliseconds */
#define SPI_DEFAULT_TIMEOUT           10
/* 250 microseconds */
#define SPI_TRYLOCK_DELAY             250

/* Data Mover burst size */
#define DM_BURST_SIZE                 16
/* Data Mover commands should be aligned to 64 bit(8 bytes) */
#define DM_BYTE_ALIGN                 8

#define SPI_QUP_VERSION_NONE      0x0
#define SPI_QUP_VERSION_BFAM      0x2

static char const * const spi_rsrcs[] = {
	"spi_clk",
	"spi_miso",
	"spi_mosi"
};

static char const * const spi_cs_rsrcs[] = {
	"spi_cs",
	"spi_cs1",
	"spi_cs2",
	"spi_cs3",
};

enum msm_spi_mode {
	SPI_FIFO_MODE  = 0x0,  /* 00 */
	SPI_BLOCK_MODE = 0x1,  /* 01 */
	SPI_DMOV_MODE  = 0x2,  /* 10 */
	SPI_BAM_MODE   = 0x3,  /* 11 */
	SPI_MODE_NONE  = 0xFF, /* invalid value */
};

/* Structure for SPI CS GPIOs */
struct spi_cs_gpio {
	int  gpio_num;
	bool valid;
};

/* Structures for Data Mover */
struct spi_dmov_cmd {
	dmov_box box;      /* data aligned to max(dm_burst_size, block_size)
							   (<= fifo_size) */
	dmov_s single_pad; /* data unaligned to max(dm_burst_size, block_size)
			      padded to fit */
	dma_addr_t cmd_ptr;
};

static struct pm_qos_request_list qos_req_list;

#ifdef CONFIG_DEBUG_FS
/* Used to create debugfs entries */
static const struct {
	const char *name;
	mode_t mode;
	int offset;
} debugfs_spi_regs[] = {
	{"config",                S_IRUGO | S_IWUSR, SPI_CONFIG},
	{"io_control",            S_IRUGO | S_IWUSR, SPI_IO_CONTROL},
	{"io_modes",              S_IRUGO | S_IWUSR, SPI_IO_MODES},
	{"sw_reset",                        S_IWUSR, SPI_SW_RESET},
	{"time_out_current",      S_IRUGO,           SPI_TIME_OUT_CURRENT},
	{"mx_output_count",       S_IRUGO | S_IWUSR, SPI_MX_OUTPUT_COUNT},
	{"mx_output_cnt_current", S_IRUGO,           SPI_MX_OUTPUT_CNT_CURRENT},
	{"mx_input_count",        S_IRUGO | S_IWUSR, SPI_MX_INPUT_COUNT},
	{"mx_input_cnt_current",  S_IRUGO,           SPI_MX_INPUT_CNT_CURRENT},
	{"mx_read_count",         S_IRUGO | S_IWUSR, SPI_MX_READ_COUNT},
	{"mx_read_cnt_current",   S_IRUGO,           SPI_MX_READ_CNT_CURRENT},
	{"operational",           S_IRUGO | S_IWUSR, SPI_OPERATIONAL},
	{"error_flags",           S_IRUGO | S_IWUSR, SPI_ERROR_FLAGS},
	{"error_flags_en",        S_IRUGO | S_IWUSR, SPI_ERROR_FLAGS_EN},
	{"deassert_wait",         S_IRUGO | S_IWUSR, SPI_DEASSERT_WAIT},
	{"output_debug",          S_IRUGO,           SPI_OUTPUT_DEBUG},
	{"input_debug",           S_IRUGO,           SPI_INPUT_DEBUG},
	{"test_ctrl",             S_IRUGO | S_IWUSR, SPI_TEST_CTRL},
	{"output_fifo",                     S_IWUSR, SPI_OUTPUT_FIFO},
	{"input_fifo" ,           S_IRUSR,           SPI_INPUT_FIFO},
	{"spi_state",             S_IRUGO | S_IWUSR, SPI_STATE},
#if defined(CONFIG_SPI_QSD) || defined(CONFIG_SPI_QSD_MODULE)
	{"fifo_word_cnt",         S_IRUGO,           SPI_FIFO_WORD_CNT},
#else
	{"qup_config",            S_IRUGO | S_IWUSR, QUP_CONFIG},
	{"qup_error_flags",       S_IRUGO | S_IWUSR, QUP_ERROR_FLAGS},
	{"qup_error_flags_en",    S_IRUGO | S_IWUSR, QUP_ERROR_FLAGS_EN},
	{"mx_write_cnt",          S_IRUGO | S_IWUSR, QUP_MX_WRITE_COUNT},
	{"mx_write_cnt_current",  S_IRUGO,           QUP_MX_WRITE_CNT_CURRENT},
	{"output_fifo_word_cnt",  S_IRUGO,           SPI_OUTPUT_FIFO_WORD_CNT},
	{"input_fifo_word_cnt",   S_IRUGO,           SPI_INPUT_FIFO_WORD_CNT},
#endif
};
#endif

struct msm_spi {
	u8                      *read_buf;
	const u8                *write_buf;
	void __iomem            *base;
	struct device           *dev;
	spinlock_t               queue_lock;
	struct mutex             core_lock;
	struct list_head         queue;
	struct workqueue_struct *workqueue;
	struct work_struct       work_data;
	struct spi_message      *cur_msg;
	struct spi_transfer     *cur_transfer;
	struct completion        transfer_complete;
	struct clk              *clk;
	struct clk              *pclk;
	unsigned long            mem_phys_addr;
	size_t                   mem_size;
	int                      input_fifo_size;
	int                      output_fifo_size;
	u32                      rx_bytes_remaining;
	u32                      tx_bytes_remaining;
	u32                      clock_speed;
	int                      irq_in;
	int                      read_xfr_cnt;
	int                      write_xfr_cnt;
	int                      write_len;
	int                      read_len;
#if defined(CONFIG_SPI_QSD) || defined(CONFIG_SPI_QSD_MODULE)
	int                      irq_out;
	int                      irq_err;
#endif
	int                      bytes_per_word;
	bool                     suspended;
	bool                     transfer_pending;
	wait_queue_head_t        continue_suspend;
	/* DMA data */
	enum msm_spi_mode        mode;
	bool                     use_dma;
	int                      tx_dma_chan;
	int                      tx_dma_crci;
	int                      rx_dma_chan;
	int                      rx_dma_crci;
	/* Data Mover Commands */
	struct spi_dmov_cmd      *tx_dmov_cmd;
	struct spi_dmov_cmd      *rx_dmov_cmd;
	/* Physical address of the tx dmov box command */
	dma_addr_t               tx_dmov_cmd_dma;
	dma_addr_t               rx_dmov_cmd_dma;
	struct msm_dmov_cmd      tx_hdr;
	struct msm_dmov_cmd      rx_hdr;
	int                      input_block_size;
	int                      output_block_size;
	int                      burst_size;
	atomic_t                 rx_irq_called;
	atomic_t                 tx_irq_called;
	/* Used to pad messages unaligned to block size */
	u8                       *tx_padding;
	dma_addr_t               tx_padding_dma;
	u8                       *rx_padding;
	dma_addr_t               rx_padding_dma;
	u32                      unaligned_len;
	/* DMA statistics */
	int                      stat_dmov_tx_err;
	int                      stat_dmov_rx_err;
	int                      stat_rx;
	int                      stat_dmov_rx;
	int                      stat_tx;
	int                      stat_dmov_tx;
#ifdef CONFIG_DEBUG_FS
	struct dentry *dent_spi;
	struct dentry *debugfs_spi_regs[ARRAY_SIZE(debugfs_spi_regs)];
#endif
	struct msm_spi_platform_data *pdata; /* Platform data */
	/* Remote Spinlock Data */
	bool                     use_rlock;
	remote_mutex_t           r_lock;
	uint32_t                 pm_lat;
	/* When set indicates multiple transfers in a single message */
	bool                     multi_xfr;
	bool                     done;
	u32                      cur_msg_len;
	/* Used in FIFO mode to keep track of the transfer being processed */
	struct spi_transfer     *cur_tx_transfer;
	struct spi_transfer     *cur_rx_transfer;
	/* Temporary buffer used for WR-WR or WR-RD transfers */
	u8                      *temp_buf;
	/* GPIO pin numbers for SPI clk, miso and mosi */
	int                      spi_gpios[ARRAY_SIZE(spi_rsrcs)];
	/* SPI CS GPIOs for each slave */
	struct spi_cs_gpio       cs_gpios[ARRAY_SIZE(spi_cs_rsrcs)];
	int                      qup_ver;
};

/* Forward declaration */
static irqreturn_t msm_spi_input_irq(int irq, void *dev_id);
static irqreturn_t msm_spi_output_irq(int irq, void *dev_id);
static irqreturn_t msm_spi_error_irq(int irq, void *dev_id);
static inline int msm_spi_set_state(struct msm_spi *dd,
				    enum msm_spi_state state);
static void msm_spi_write_word_to_fifo(struct msm_spi *dd);
static inline void msm_spi_write_rmn_to_fifo(struct msm_spi *dd);
static inline irqreturn_t msm_spi_qup_irq(int irq, void *dev_id);

#if defined(CONFIG_SPI_QSD) || defined(CONFIG_SPI_QSD_MODULE)
static inline void msm_spi_disable_irqs(struct msm_spi *dd)
{
	disable_irq(dd->irq_in);
	disable_irq(dd->irq_out);
	disable_irq(dd->irq_err);
}

static inline void msm_spi_enable_irqs(struct msm_spi *dd)
{
	enable_irq(dd->irq_in);
	enable_irq(dd->irq_out);
	enable_irq(dd->irq_err);
}

static inline int msm_spi_request_irq(struct msm_spi *dd,
				struct platform_device *pdev,
				struct spi_master *master)
{
	int rc;

	dd->irq_in  = platform_get_irq(pdev, 0);
	dd->irq_out = platform_get_irq(pdev, 1);
	dd->irq_err = platform_get_irq(pdev, 2);
	if ((dd->irq_in < 0) || (dd->irq_out < 0) || (dd->irq_err < 0))
		return -EINVAL;

	rc = devm_request_irq(dd->dev, dd->irq_in, msm_spi_input_irq,
		IRQF_TRIGGER_RISING, pdev->name, dd);
	if (rc)
		goto error_irq;

	rc = devm_request_irq(dd->dev, dd->irq_out, msm_spi_output_irq,
		IRQF_TRIGGER_RISING, pdev->name, dd);
	if (rc)
		goto error_irq;

	rc = devm_request_irq(dd->dev, dd->irq_err, msm_spi_error_irq,
		IRQF_TRIGGER_RISING, pdev->name, master);
	if (rc)
		goto error_irq;

error_irq:
	return rc;
}

static inline void msm_spi_get_clk_err(struct msm_spi *dd, u32 *spi_err) {}
static inline void msm_spi_ack_clk_err(struct msm_spi *dd) {}
static inline void msm_spi_set_qup_config(struct msm_spi *dd, int bpw) {}

static inline int msm_spi_prepare_for_write(struct msm_spi *dd) { return 0; }
static inline void msm_spi_start_write(struct msm_spi *dd, u32 read_count)
{
	msm_spi_write_word_to_fifo(dd);
}
static inline void msm_spi_set_write_count(struct msm_spi *dd, int val) {}

static inline void msm_spi_complete(struct msm_spi *dd)
{
	complete(&dd->transfer_complete);
}

static inline void msm_spi_enable_error_flags(struct msm_spi *dd)
{
	writel_relaxed(0x0000007B, dd->base + SPI_ERROR_FLAGS_EN);
}

static inline void msm_spi_clear_error_flags(struct msm_spi *dd)
{
	writel_relaxed(0x0000007F, dd->base + SPI_ERROR_FLAGS);
}

#else
/* In QUP the same interrupt line is used for input, output and error*/
static inline int msm_spi_request_irq(struct msm_spi *dd,
				struct platform_device *pdev,
				struct spi_master *master)
{
	dd->irq_in  = platform_get_irq(pdev, 0);
	if (dd->irq_in < 0)
		return -EINVAL;

	return devm_request_irq(dd->dev, dd->irq_in, msm_spi_qup_irq,
		IRQF_TRIGGER_HIGH, pdev->name, dd);
}

static inline void msm_spi_disable_irqs(struct msm_spi *dd)
{
	disable_irq(dd->irq_in);
}

static inline void msm_spi_enable_irqs(struct msm_spi *dd)
{
	enable_irq(dd->irq_in);
}

static inline void msm_spi_get_clk_err(struct msm_spi *dd, u32 *spi_err)
{
	*spi_err = readl_relaxed(dd->base + QUP_ERROR_FLAGS);
}

static inline void msm_spi_ack_clk_err(struct msm_spi *dd)
{
	writel_relaxed(QUP_ERR_MASK, dd->base + QUP_ERROR_FLAGS);
}

static inline void msm_spi_add_configs(struct msm_spi *dd, u32 *config, int n);

/* QUP has no_input, no_output, and N bits at QUP_CONFIG */
static inline void msm_spi_set_qup_config(struct msm_spi *dd, int bpw)
{
	u32 qup_config = readl_relaxed(dd->base + QUP_CONFIG);

	msm_spi_add_configs(dd, &qup_config, bpw-1);
	writel_relaxed(qup_config | QUP_CONFIG_SPI_MODE,
		       dd->base + QUP_CONFIG);
}

static inline int msm_spi_prepare_for_write(struct msm_spi *dd)
{
	if (msm_spi_set_state(dd, SPI_OP_STATE_RUN))
		return -EINVAL;
	if (msm_spi_set_state(dd, SPI_OP_STATE_PAUSE))
		return -EINVAL;
	return 0;
}

static inline void msm_spi_start_write(struct msm_spi *dd, u32 read_count)
{
	if (read_count <= dd->input_fifo_size)
		msm_spi_write_rmn_to_fifo(dd);
	else
		msm_spi_write_word_to_fifo(dd);
}

static inline void msm_spi_set_write_count(struct msm_spi *dd, int val)
{
	writel_relaxed(val, dd->base + QUP_MX_WRITE_COUNT);
}

static inline void msm_spi_complete(struct msm_spi *dd)
{
	dd->done = 1;
}

static inline void msm_spi_enable_error_flags(struct msm_spi *dd)
{
	writel_relaxed(0x00000078, dd->base + SPI_ERROR_FLAGS_EN);
}

static inline void msm_spi_clear_error_flags(struct msm_spi *dd)
{
	writel_relaxed(0x0000007C, dd->base + SPI_ERROR_FLAGS);
}

#endif
#endif