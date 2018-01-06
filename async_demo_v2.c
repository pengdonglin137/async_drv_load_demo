#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/delay.h>

#define USE_ASYNC

static int async_demo1_v2_probe(struct platform_device *pdev)
{
	if (pdev->dev.parent)
		printk("%s: parent %s\n", __func__, dev_name(pdev->dev.parent));
	printk("%s enter.\n", __func__);
	msleep(4000);
	printk("%s exit.\n", __func__);
	return 0;
}

static int async_demo1_v2_remove(struct platform_device *pdev)
{
	printk("%s enter.\n", __func__);
	return 0;
}

static const struct of_device_id async_demo1_v2_dt_ids[] = {
	{ .compatible = "async_demo1_v2", },
	{  }
};
MODULE_DEVICE_TABLE(of, async_demo1_v2_dt_ids);

static struct platform_driver async_demo1_v2_driver = {
	.probe		= async_demo1_v2_probe,
	.remove		= async_demo1_v2_remove,
	.driver		= {
		.name	= "async_demo1_v2",
		.of_match_table = of_match_ptr(async_demo1_v2_dt_ids),
#ifdef USE_ASYNC
		.probe_type = PROBE_PREFER_ASYNCHRONOUS,
#else
		.probe_type = PROBE_FORCE_SYNCHRONOUS,
#endif
	},
};

static int async_demo2_v2_probe(struct platform_device *pdev)
{
	if (pdev->dev.parent)
		printk("%s: parent %s\n", __func__, dev_name(pdev->dev.parent));
	printk("%s enter.\n", __func__);
	msleep(3000);
	printk("%s exit.\n", __func__);
	return 0;
}

static int async_demo2_v2_remove(struct platform_device *pdev)
{
	printk("%s enter.\n", __func__);
	return 0;
}

static const struct of_device_id async_demo2_v2_dt_ids[] = {
	{ .compatible = "async_demo2_v2", },
	{  }
};
MODULE_DEVICE_TABLE(of, async_demo2_v2_dt_ids);

static struct platform_driver async_demo2_v2_driver = {
	.probe		= async_demo2_v2_probe,
	.remove		= async_demo2_v2_remove,
	.driver		= {
		.name	= "async_demo2_v2",
		.of_match_table = of_match_ptr(async_demo2_v2_dt_ids),
#ifdef USE_ASYNC
		.probe_type = PROBE_PREFER_ASYNCHRONOUS,
#else
		.probe_type = PROBE_FORCE_SYNCHRONOUS,
#endif
	},
};

static int async_demo3_v2_probe(struct platform_device *pdev)
{
	printk("%s enter.\n", __func__);
	msleep(2000);
	printk("%s exit.\n", __func__);
	return 0;
}

static int async_demo3_v2_remove(struct platform_device *pdev)
{
	printk("%s enter.\n", __func__);
	return 0;
}

static const struct of_device_id async_demo3_v2_dt_ids[] = {
	{ .compatible = "async_demo3_v2", },
	{  }
};
MODULE_DEVICE_TABLE(of, async_demo3_v2_dt_ids);

static struct platform_driver async_demo3_v2_driver = {
	.probe		= async_demo3_v2_probe,
	.remove		= async_demo3_v2_remove,
	.driver		= {
		.name	= "async_demo3_v2",
		.of_match_table = of_match_ptr(async_demo3_v2_dt_ids),
#ifdef USE_ASYNC
		.probe_type = PROBE_PREFER_ASYNCHRONOUS,
#else
		.probe_type = PROBE_FORCE_SYNCHRONOUS,
#endif
	},
};

static int async_demo4_v2_probe(struct platform_device *pdev)
{
	printk("%s enter.\n", __func__);
	msleep(1000);
	printk("%s exit.\n", __func__);
	return 0;
}

static int async_demo4_v2_remove(struct platform_device *pdev)
{
	printk("%s enter.\n", __func__);
	return 0;
}

static const struct of_device_id async_demo4_v2_dt_ids[] = {
	{ .compatible = "async_demo4_v2", },
	{  }
};
MODULE_DEVICE_TABLE(of, async_demo4_v2_dt_ids);

static struct platform_driver async_demo4_v2_driver = {
	.probe		= async_demo4_v2_probe,
	.remove		= async_demo4_v2_remove,
	.driver		= {
		.name	= "async_demo4_v2",
		.of_match_table = of_match_ptr(async_demo4_v2_dt_ids),
#ifdef USE_ASYNC
		.probe_type = PROBE_PREFER_ASYNCHRONOUS,
#else
		.probe_type = PROBE_FORCE_SYNCHRONOUS,
#endif
	},
};

static __init int async_demo_init(void)
{
	printk("%s enter.\n", __func__);

	printk("Register Platform Driver\n");
	platform_driver_register(&async_demo1_v2_driver);
	platform_driver_register(&async_demo2_v2_driver);
	platform_driver_register(&async_demo3_v2_driver);
	platform_driver_register(&async_demo4_v2_driver);

	printk("\n\n Register Platform Device\n");
	platform_device_register_simple("async_demo1_v2", 0, NULL, 0);
	platform_device_register_simple("async_demo2_v2", 0, NULL, 0);
	platform_device_register_simple("async_demo3_v2", 0, NULL, 0);
	platform_device_register_simple("async_demo4_v2", 0, NULL, 0);

	return 0;
}

static __exit void async_demo_exit(void)
{
	printk("%s enter.\n", __func__);

	platform_driver_unregister(&async_demo1_v2_driver);
	platform_driver_unregister(&async_demo2_v2_driver);
	platform_driver_unregister(&async_demo3_v2_driver);
	platform_driver_unregister(&async_demo4_v2_driver);
}

module_init(async_demo_init);
module_exit(async_demo_exit);

MODULE_LICENSE("GPL");
